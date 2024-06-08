#include "qrsegment.h"

const QString ALPHANUMERIC = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";

QrSegment::QrSegment(const Mode &mode, int numChars, const QVector<bool> &data) {
    this->mode = &mode;
    this->numChars = numChars;
    this->data = data;
}


QrSegment::QrSegment(const Mode &mode, int numChars, QVector<bool> &&data) {
    this->mode = &mode;
    this->numChars = numChars;
    this->data = std::move(data);
}


bool QrSegment::isNumericFormat(const QChar *text) {
    while (*text != '\0') {
        QChar symbol = *text;
        if (symbol.unicode() < 48 || symbol.unicode() > 57) {
            return false;
        }
        text++;
    }
    return true;
}


bool QrSegment::isAlphanumericFormat(const QChar *text) {
    while (*text != '\0') {
        if (ALPHANUMERIC.indexOf(*text) == -1) {
            return false;
        }
        text++;
    }
    return true;
}


QrSegment QrSegment::createNumericSegment(const QChar *text) {
    BitBuffer bitbuffer;
    int collectCount = 0;
    int collectData = 0;
    int charCount = 0;
    while (*text != '\0') {
        QChar symbol = *text;
        collectData = collectData * 10 + (symbol.unicode() - 48);
        collectCount++;
        if (collectCount == 3) {
            bitbuffer.appendBits(static_cast<uint>(collectData), 10);
            collectCount = 0;
            collectData = 0;
        }
        charCount++;
        text++;
    }
    if (collectCount > 0) {
        if (collectCount == 2) {
            bitbuffer.appendBits(static_cast<uint>(collectData), 7);
        }
        else {
            bitbuffer.appendBits(static_cast<uint>(collectData), 4);
        }
    }
    return QrSegment(Mode::NUMERIC, charCount, std::move(bitbuffer));
}


QrSegment QrSegment::createByteSegment(const QVector<uint8_t> &data) {
    BitBuffer bitbuffer;
    for (uint8_t bit : data) {
        bitbuffer.appendBits(bit, 8);
    }
    return QrSegment(Mode::BYTE, static_cast<int>(data.size()), std::move(bitbuffer));
}


QrSegment QrSegment::createAlphanumericSegment(const QChar *text) {
    BitBuffer bitbuffer;
    int collectCount = 0;
    int collectData = 0;
    int charCount = 0;
    while (*text != '\0') {
        int symbolIndex = ALPHANUMERIC.indexOf(text);
        collectData = collectData * 45 + symbolIndex;
        collectCount++;
        if (collectCount == 2) {
            bitbuffer.appendBits(static_cast<uint>(collectData), 11);
            collectData = 0;
            collectCount = 0;
        }
        charCount++;
        text++;
    }
    if (collectCount > 0) {
        bitbuffer.appendBits(static_cast<uint>(collectData), 6);
    }
    return QrSegment(Mode::ALPHANUMERIC, charCount, std::move(bitbuffer));
}


QVector<QrSegment> QrSegment::buildSegments(const QChar *text) {
    QVector<QrSegment> result;
    //if (*text == '\0');
    if (isNumericFormat(text)) {
        result.push_back(createNumericSegment(text));
    }
    else if (isAlphanumericFormat(text)) {
        result.push_back(createAlphanumericSegment(text));
    }
    else {
        QVector<uint8_t> bytes;
        while (*text != '\0') {
            bytes.push_back(static_cast<uint8_t>(text->unicode()));
            text++;
        }
        result.push_back(createByteSegment(bytes));
    }
    return result;
}


QrSegment QrSegment::makeEci(long value) {
    BitBuffer bitbuffer;
    if (value < 128) {                                        //8 бит
        bitbuffer.appendBits(static_cast<uint32_t>(value), 8);
    }
    else if (value < 16384) {                                      //14 бит
        bitbuffer.appendBits(2, 2);
        bitbuffer.appendBits(static_cast<uint32_t>(value), 14);
    }
    else if (value < 1000000L) {
        bitbuffer.appendBits(6, 3);
        bitbuffer.appendBits(static_cast<uint32_t>(value), 21);
    }
    return QrSegment(Mode::ECI, 0, std::move(bitbuffer));
}


int QrSegment::getTotalBits(const QVector<QrSegment> &segs, int version) {
    int result = 0;
    const int SEGMENT_MODE_CODE = 4;
    for (const QrSegment &seg : segs) {
        int mergeBits = seg.mode->numCharCountBits(version);
        if (seg.numChars >= (1L << mergeBits)) {
            return -1;
        }
        if (SEGMENT_MODE_CODE + mergeBits > INT_MAX - result) {
            return -1;
        }
        result += SEGMENT_MODE_CODE + mergeBits;
        if (seg.data.size() > static_cast<uint>(INT_MAX - result)) {
            return -1;
        }
        result += static_cast<int>(seg.data.size());
    }
    return result;
}


const Mode &QrSegment::getMode() const {
    return *mode;
}


int QrSegment::getNumChars() const {
    return numChars;
}


const QVector<bool> &QrSegment::getData() const {
    return data;
}



