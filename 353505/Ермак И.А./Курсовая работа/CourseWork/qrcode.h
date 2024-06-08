#ifndef QRCODE_H
#define QRCODE_H

#include <array>
#include <cstdint>
// #include <algorithm>
#include <climits>
//#include <cstddef>
// #include <cstdlib>
// #include <cstring>
//#include <utility>
#include <qrsegment.h>
#include <QVector>

class QrCode
{
public:
    QrCode();

    public:
        enum class Ecc {
            LOW,
            MEDIUM,
            QUARTILE,
            HIGH,
        };
    private:
        static int getFormatBits(Ecc ecl);
    public:
        static QrCode encodeText(const QChar*, Ecc);
        static QrCode encodeBinary(const QVector<uint8_t>&, Ecc);

    public:
        static QrCode encodeSegments(const QVector<QrSegment> &segs, Ecc, uint minV = 1, uint maxV = 40, int mask = -1);

    private:
        int version;
        uint size;
        Ecc errorCorrectionLevel;
        int mask;
        QVector<QVector<bool> > modules;
        QVector<QVector<bool> > IsUtilityModul;

    public:
        QrCode(uint, Ecc, const QVector<uint8_t>&, int);
        int getVersion() const;
        int getSize() const;
        Ecc getErrorCorrectionLevel() const;
        int getMask() const;
        bool getModule(int, int) const;

    private:
        void SetupUtilityPatterns();
        void SetupFormatBits(int);
        void SetupVersion();
        void SetupFindPattern(int, int);
        void SetupAlignPattern(int, int);
        void SetupCodewords(const QVector<uint8_t>&);
        void SetupMask(int);
        QVector<uint8_t> SetupEccAndInterleave(const QVector<uint8_t>&) const;

        void setFunctionModule(int, int, bool);
        bool module(int, int) const;

        long getPenaltyScore() const;
        QVector<int> getAlignmentPatternPositions() const;

        static int getNumRawDataModules(int);
        static int getNumCodewords(int, Ecc);

        static QVector<uint8_t> reedSolomonComputeDivisor(int);
        static QVector<uint8_t> reedSolomonComputeRemainder(const QVector<uint8_t>&, const QVector<uint8_t>&);
        static uint8_t reedSolomonMultiply(uint8_t, uint8_t);

        int finderPenaltyCountPatterns(const std::array<int,7>&) const;
        int finderPenaltyTerminateAndCount(bool, int, std::array<int,7>&) const;
        void finderPenaltyAddHistory(int, std::array<int,7>&) const;

    private:
        static bool getBit(long, int);

    public:
        const int MIN_VERSION = 1;
        const int MAX_VERSION = 40;

    private:
        const int PENALTY_N1 = 3;
        const int PENALTY_N2 = 3;
        const int PENALTY_N3 = 40;
        const int PENALTY_N4 = 10;

    private:
        static const int8_t ECC_CODEWORDS_IN_BLOCK[4][41];
        static const int8_t NUM_ERROR_CORRECTION_BLOCKS[4][41];
};

#endif // QRCODE_H
