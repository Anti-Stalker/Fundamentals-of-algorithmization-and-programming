#include "qrcode.h"

QrCode::QrCode(uint version, Ecc errorCorrectionLevel, const QVector<uint8_t> &codewords, int mask) {
    this->version = version;
    size = version * 4 + 17;
    this->errorCorrectionLevel = errorCorrectionLevel;
    modules = QVector<QVector<bool> >(size, QVector<bool>(size));
    IsUtilityModul = QVector<QVector<bool> >(size, QVector<bool>(size));

    SetupUtilityPatterns();
    const QVector<uint8_t> allCodewords = SetupEccAndInterleave(codewords);
    SetupCodewords(allCodewords);

    if (mask == -1) {
        long minPenalty = LONG_MAX;
        for (int i = 0; i < 8; i++) {
            SetupMask(i);
            SetupFormatBits(i);
            long penalty = getPenaltyScore();
            if (penalty < minPenalty) {
                mask = i;
                minPenalty = penalty;
            }
            SetupMask(i);
        }
    }
    this->mask = mask;
    SetupMask(mask);
    SetupFormatBits(mask);
    IsUtilityModul.clear();
}


QrCode QrCode::encodeText(const QChar *text, Ecc ecl) {
    QVector<QrSegment> segs = QrSegment::buildSegments(text);
    return encodeSegments(segs, ecl);
}


QrCode QrCode::encodeBinary(const QVector<uint8_t> &data, Ecc ecl) {
    QVector<QrSegment> segs{QrSegment::createByteSegment(data)};
    return encodeSegments(segs, ecl);
}


QrCode QrCode::encodeSegments(const QVector<QrSegment> &segs, Ecc ecl,
                              uint minVersion, uint maxVersion, int mask) {
    int version;
    int dataUsedBits;
    for (version = minVersion; ; version++) {
        int capacityBits = getNumCodewords(version, ecl) * 8;
        dataUsedBits = QrSegment::getTotalBits(segs, version);
        if (dataUsedBits != -1 && dataUsedBits <= capacityBits) {
            break;
        }
    }

    BitBuffer bitbuffer;
    for (const QrSegment &seg : segs) {
        bitbuffer.appendBits(static_cast<uint32_t>(seg.getMode().getModeBits()), 4);
        bitbuffer.appendBits(static_cast<uint32_t>(seg.getNumChars()), seg.getMode().numCharCountBits(version));
        for (bool bit : seg.getData()) {
            bitbuffer.append(bit);
        }
    }

    size_t capacityBits = static_cast<size_t>(getNumCodewords(version, ecl)) * 8;
    bitbuffer.appendBits(0, std::min(4, static_cast<int>(capacityBits - bitbuffer.size())));
    bitbuffer.appendBits(0, (8 - static_cast<int>(bitbuffer.size() % 8)) % 8);

    for (uint8_t padByte = 236; bitbuffer.size() < capacityBits; padByte ^= 236 ^ 17)
        bitbuffer.appendBits(padByte, 8);

    QVector<uint8_t> codewords(bitbuffer.size() / 8);
    for (size_t i = 0; i < bitbuffer.size(); i++)
        codewords[i / 8] |= (bitbuffer[i] ? 1 : 0) << (7 - (i & 7));

    return QrCode(version, ecl, codewords, mask);
}


int QrCode::getVersion() const {
    return version;
}


int QrCode::getSize() const {
    return size;
}


QrCode::Ecc QrCode::getErrorCorrectionLevel() const {
    return errorCorrectionLevel;
}


int QrCode::getMask() const {
    return mask;
}


bool QrCode::getModule(int x, int y) const {
    if (0 <= x && x <= size - 1 && 0 <= y && y <= size - 1) {
        return  module(x, y);
    }
    return false;
}


void QrCode::SetupUtilityPatterns() {
    for (int i = 0; i < size; i++) {
        setFunctionModule(6, i, i % 2 == 0);
        setFunctionModule(i, 6, i % 2 == 0);
    }

    SetupFindPattern(3, 3);
    SetupFindPattern(size - 4, 3);
    SetupFindPattern(3, size - 4);

    const QVector<int> alignPatPos = getAlignmentPatternPositions();
    size_t numAlign = alignPatPos.size();
    for (size_t i = 0; i < numAlign; i++) {
        for (size_t j = 0; j < numAlign; j++) {

            if (!((i == 0 && j == 0) || (i == 0 && j == numAlign - 1) || (i == numAlign - 1 && j == 0)))
                SetupAlignPattern(alignPatPos[i], alignPatPos[j]);
        }
    }

    SetupFormatBits(0);
    SetupVersion();
}


void QrCode::SetupFormatBits(int msk) {
    int data = getFormatBits(errorCorrectionLevel) << 3 | msk;
    int rem = data;
    for (int i = 0; i < 10; i++)
        rem = (rem << 1) ^ ((rem >> 9) * 1335);
    int bits = (data * 1024 | rem) ^ 21522;

    for (int i = 0; i <= 5; i++)
        setFunctionModule(8, i, getBit(bits, i));
    setFunctionModule(8, 7, getBit(bits, 6));
    setFunctionModule(8, 8, getBit(bits, 7));
    setFunctionModule(7, 8, getBit(bits, 8));
    for (int i = 9; i < 15; i++)
        setFunctionModule(14 - i, 8, getBit(bits, i));

    for (int i = 0; i < 8; i++)
        setFunctionModule(size - i - 1, 8, getBit(bits, i));
    for (int i = 8; i < 15; i++)
        setFunctionModule(8, size + i - 15, getBit(bits, i));
    setFunctionModule(8, size - 8, true);
}


void QrCode::SetupVersion() {
    if (version < 7)
        return;

    int rem = version;
    for (int i = 0; i < 12; i++)
        rem = (rem * 2) ^ ((rem / 2048) * 7985);
    long bits = static_cast<long>(version) << 12 | rem;

    for (int i = 0; i < 18; i++) {
        bool bit = getBit(bits, i);
        int a = size - 11 + i % 3;
        int b = i / 3;
        setFunctionModule(a, b, bit);
        setFunctionModule(b, a, bit);
    }
}


void QrCode::SetupFindPattern(int x, int y) {
    for (int dy = -4; dy <= 4; dy++) {
        for (int dx = -4; dx <= 4; dx++) {
            int dist = std::max(std::abs(dx), std::abs(dy));
            int xx = x + dx, yy = y + dy;
            if (0 <= xx && xx < size && 0 <= yy && yy < size)
                setFunctionModule(xx, yy, dist != 2 && dist != 4);
        }
    }
}


void QrCode::SetupAlignPattern(int x, int y) {
    for (int dy = -2; dy <= 2; dy++) {
        for (int dx = -2; dx <= 2; dx++)
            setFunctionModule(x + dx, y + dy, std::max(std::abs(dx), std::abs(dy)) != 1);
    }
}


void QrCode::setFunctionModule(int x, int y, bool isDark) {
    size_t ux = static_cast<size_t>(x);
    size_t uy = static_cast<size_t>(y);
    modules[uy][ux] = isDark;
    IsUtilityModul[uy][ux] = true;
}


bool QrCode::module(int x, int y) const {
    return modules[static_cast<size_t>(y)][static_cast<size_t>(x)];
}


QVector<uint8_t> QrCode::SetupEccAndInterleave(const QVector<uint8_t> &data) const {
    int blockEccLength = ECC_CODEWORDS_IN_BLOCK[static_cast<int>(errorCorrectionLevel)][version];
    int numBlocks = NUM_ERROR_CORRECTION_BLOCKS[static_cast<int>(errorCorrectionLevel)][version];
    int unrefinedCodewords = getNumRawDataModules(version) / 8;
    int numShortBlocks = numBlocks - unrefinedCodewords % numBlocks;
    int shortBlockLength = unrefinedCodewords / numBlocks;
    QVector<QVector<uint8_t> > blocks;
    QVector<uint8_t> result;
    const QVector<uint8_t> READ_SOLOMON_DIVISOR = reedSolomonComputeDivisor(blockEccLength);
    for (int i = 0, j = 0; i < numBlocks; i++) {
        QVector<uint8_t> dat(data.cbegin() + j, data.cbegin() + (j + shortBlockLength - blockEccLength + (i < numShortBlocks ? 0 : 1)));
        j += static_cast<int>(dat.size());
        const QVector<uint8_t> ecc = reedSolomonComputeRemainder(dat, READ_SOLOMON_DIVISOR);
        if (i < numShortBlocks)
            dat.push_back(0);
        for (uint8_t byte : ecc) {
            dat.append(byte);
        }
        blocks.push_back(std::move(dat));
    }
    for (size_t i = 0; i < blocks[0].size(); i++) {
        for (size_t j = 0; j < blocks.size(); j++) {
            if (i != static_cast<uint>(shortBlockLength - blockEccLength) || j >= static_cast<uint>(numShortBlocks))
                result.push_back(blocks[j][i]);
        }
    }
    return result;
}


void QrCode::SetupCodewords(const QVector<uint8_t> &data) {
    size_t i = 0;
    for (int right = size - 1; right >= 1; right -= 2) {
        if (right == 6) {
            right = 5;
        }
        for (int vert = 0; vert < size; vert++) {
            for (int j = 0; j < 2; j++) {
                size_t x = static_cast<size_t>(right - j);
                bool upward = ((right + 1) & 2) == 0;
                size_t y = static_cast<size_t>(upward ? size - 1 - vert : vert);
                if (!IsUtilityModul[y][x] && i < data.size() * 8) {
                    modules[y][x] = getBit(data[i >> 3], 7 - static_cast<int>(i & 7));
                    i++;
                }
            }
        }
    }
}


void QrCode::SetupMask(int msk) {
    for (size_t y = 0; y < size; y++) {
        for (size_t x = 0; x < size; x++) {
            bool inv = false;
            switch (msk) {
            case 0:
                inv = (x + y) % 2 == 0;
                break;
            case 1:
                inv = y % 2 == 0;
                break;
            case 2:
                inv = x % 3 == 0;
                break;
            case 3:
                inv = (x + y) % 3 == 0;
                break;
            case 4:
                inv = (x / 3 + y / 2) % 2 == 0;
                break;
            case 5:
                inv = x * y % 2 + x * y % 3 == 0;
                break;
            case 6:
                inv = (x * y % 2 + x * y % 3) % 2 == 0;
                break;
            case 7:
                inv = ((x + y) % 2 + x * y % 3) % 2 == 0;
                break;
            default:
                return;
            }
            modules[y][x] = modules[y][x] ^ (inv & !IsUtilityModul[y][x]);
        }
    }
}


long QrCode::getPenaltyScore() const {
    long result = 0;
    for (int y = 0; y < size; y++) {
        bool sequenceColor = false;
        int sequenceX = 0;
        std::array<int,7> sequenceLengths = {};
        for (int x = 0; x < size; x++) {
            if (module(x, y) == sequenceColor) {
                sequenceX++;
                if (sequenceX == 5)
                    result += PENALTY_N1;
                else if (sequenceX > 5)
                    result++;
            } else {
                finderPenaltyAddHistory(sequenceX, sequenceLengths);
                if (!sequenceColor)
                    result += finderPenaltyCountPatterns(sequenceLengths) * PENALTY_N3;
                sequenceColor = module(x, y);
                sequenceX = 1;
            }
        }
        result += finderPenaltyTerminateAndCount(sequenceColor, sequenceX, sequenceLengths) * PENALTY_N3;
    }
    for (int x = 0; x < size; x++) {
        bool sequenceColor = false;
        int sequenceY = 0;
        std::array<int,7> sequenceLengths = {};
        for (int y = 0; y < size; y++) {
            if (module(x, y) == sequenceColor) {
                sequenceY++;
                if (sequenceY == 5)
                    result += PENALTY_N1;
                else if (sequenceY > 5)
                    result++;
            } else {
                finderPenaltyAddHistory(sequenceY, sequenceLengths);
                if (!sequenceColor)
                    result += finderPenaltyCountPatterns(sequenceLengths) * PENALTY_N3;
                sequenceColor = module(x, y);
                sequenceY = 1;
            }
        }
        result += finderPenaltyTerminateAndCount(sequenceColor, sequenceY, sequenceLengths) * PENALTY_N3;
    }

    for (int y = 0; y < size - 1; y++) {
        for (int x = 0; x < size - 1; x++) {
            bool  color = module(x, y);
            if (  color == module(x + 1, y) &&
                color == module(x, y + 1) &&
                color == module(x + 1, y + 1))
                result += PENALTY_N2;
        }
    }

    int dark = 0;
    for (const QVector<bool> &row : modules) {
        for (bool color : row) {
            if (color)
                dark++;
        }
    }
    int total = size * size;
    int k = static_cast<int>((std::abs(dark * 20L - total * 10L) + total - 1) / total) - 1;
    result += k * PENALTY_N4;
    return result;
}


QVector<int> QrCode::getAlignmentPatternPositions() const {
    if (version == 1) {
        return QVector<int>();
    }
    else {
        int numAlign = version / 7 + 2;
        int step = (version == 32) ? 26 :
                       (version * 4 + numAlign * 2 + 1) / (numAlign * 2 - 2) * 2;
        QVector<int> result;
        for (int i = 0, pos = size - 7; i < numAlign - 1; i++, pos -= step)
            result.insert(result.begin(), pos);
        result.insert(result.begin(), 6);
        return result;
    }
}


int QrCode::getNumRawDataModules(int ver) {
    int result = (16 * ver + 128) * ver + 64;
    if (ver >= 2) {
        int numAlign = ver / 7 + 2;
        result -= (25 * numAlign - 10) * numAlign - 55;
        if (ver >= 7)
            result -= 36;
    }
    return result;
}


int QrCode::getNumCodewords(int ver, Ecc ecl) {
    return getNumRawDataModules(ver) / 8
           - ECC_CODEWORDS_IN_BLOCK    [static_cast<int>(ecl)][ver]
                 * NUM_ERROR_CORRECTION_BLOCKS[static_cast<int>(ecl)][ver];
}


QVector<uint8_t> QrCode::reedSolomonComputeDivisor(int degree) {
    QVector<uint8_t> result(static_cast<size_t>(degree));
    result[result.size() - 1] = 1;
    uint8_t root = 1;
    for (int i = 0; i < degree; i++) {
        for (size_t j = 0; j < result.size(); j++) {
            result[j] = reedSolomonMultiply(result[j], root);
            if (j + 1 < result.size()) {
                result[j] ^= result[j + 1];
            }
        }
        root = reedSolomonMultiply(root, 2);
    }
    return result;
}


QVector<uint8_t> QrCode::reedSolomonComputeRemainder(const QVector<uint8_t> &data, const QVector<uint8_t> &divisor) {
    QVector<uint8_t> result(divisor.size());
    for (uint8_t b : data) {
        uint8_t factor = b ^ result[0];
        result.erase(result.begin());
        result.push_back(0);
        for (size_t i = 0; i < result.size(); i++) {
            result[i] ^= reedSolomonMultiply(divisor[i], factor);
        }
    }
    return result;
}


uint8_t QrCode::reedSolomonMultiply(uint8_t x, uint8_t y) {
    int z = 0;
    for (int i = 7; i >= 0; i--) {
        z = (z << 1) ^ ((z >> 7) * 285);
        z ^= ((y >> i) & 1) * x;
    }

    return static_cast<uint8_t>(z);
}


int QrCode::finderPenaltyCountPatterns(const std::array<int,7> &sequenceLengths) const {
    int n = sequenceLengths[1];
    bool core = n > 0 && sequenceLengths[2] == n && sequenceLengths[3] == n * 3 && sequenceLengths[4] == n && sequenceLengths[5] == n;
    return (core && sequenceLengths[0] >= n * 4 && sequenceLengths[6] >= n ? 1 : 0)
           + (core && sequenceLengths[6] >= n * 4 && sequenceLengths[0] >= n ? 1 : 0);
}


int QrCode::finderPenaltyTerminateAndCount(bool currentSequenceColor, int currentSequenceLength, std::array<int,7> &sequenceLengths) const {
    if (currentSequenceColor) {
        finderPenaltyAddHistory(currentSequenceLength, sequenceLengths);
        currentSequenceLength = 0;
    }
    currentSequenceLength += size;
    finderPenaltyAddHistory(currentSequenceLength, sequenceLengths);
    return finderPenaltyCountPatterns(sequenceLengths);
}


void QrCode::finderPenaltyAddHistory(int currentSequenceLength, std::array<int,7> &sequenceLengths) const {
    if (sequenceLengths[0] == 0) {
        currentSequenceLength += size;
    }
    std::copy_backward(sequenceLengths.cbegin(), sequenceLengths.cend() - 1, sequenceLengths.end());
    sequenceLengths[0] = currentSequenceLength;
}


bool QrCode::getBit(long value, int i) {
    return ((value >> i) & 1) != 0;
}


int QrCode::getFormatBits(Ecc ecl) {
    switch (ecl) {
    case Ecc::LOW:
        return 1;
    case Ecc::MEDIUM:
        return 0;
    case Ecc::QUARTILE:
        return 3;
    case Ecc::HIGH:
        return 2;
    default:
        break;
    }
}


const int8_t QrCode::ECC_CODEWORDS_IN_BLOCK[4][41] = {
    {-1, 7, 10, 15, 20, 26, 18, 20, 24, 30, 18, 20, 24, 26, 30, 22, 24, 28, 30, 28, 28, 28, 28, 30, 30, 26, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},
    {-1, 10, 16, 26, 18, 24, 16, 18, 22, 22, 26, 30, 22, 22, 24, 24, 28, 28, 26, 26, 26, 26, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28},
    {-1, 13, 22, 18, 26, 18, 24, 18, 22, 20, 24, 28, 26, 24, 20, 30, 24, 28, 28, 26, 30, 28, 30, 30, 30, 30, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},
    {-1, 17, 28, 22, 16, 22, 28, 26, 26, 24, 28, 24, 28, 22, 24, 24, 30, 28, 28, 26, 28, 30, 24, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},
};

const int8_t QrCode::NUM_ERROR_CORRECTION_BLOCKS[4][41] = {   
    {-1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 4, 4, 4, 4, 4, 6, 6, 6, 6, 7, 8, 8, 9, 9, 10, 12, 12, 12, 13, 14, 15, 16, 17, 18, 19, 19, 20, 21, 22, 24, 25},
    {-1, 1, 1, 1, 2, 2, 4, 4, 4, 5, 5, 5, 8, 9, 9, 10, 10, 11, 13, 14, 16, 17, 17, 18, 20, 21, 23, 25, 26, 28, 29, 31, 33, 35, 37, 38, 40, 43, 45, 47, 49},
    {-1, 1, 1, 2, 2, 4, 4, 6, 6, 8, 8, 8, 10, 12, 16, 12, 17, 16, 18, 21, 20, 23, 23, 25, 27, 29, 34, 34, 35, 38, 40, 43, 45, 48, 51, 53, 56, 59, 62, 65, 68},
    {-1, 1, 1, 2, 4, 4, 4, 5, 6, 8, 8, 11, 11, 16, 16, 18, 16, 19, 21, 25, 25, 25, 34, 30, 32, 35, 37, 40, 42, 45, 48, 51, 54, 57, 60, 63, 66, 70, 74, 77, 81},
};
