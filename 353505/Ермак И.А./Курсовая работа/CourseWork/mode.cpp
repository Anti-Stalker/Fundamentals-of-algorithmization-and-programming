#include "mode.h"

Mode::Mode(int mode, int cc0, int cc1, int cc2) : modeBits(mode) {
    numBitsCharCount[0] = cc0;
    numBitsCharCount[1] = cc1;
    numBitsCharCount[2] = cc2;
}

const Mode Mode::NUMERIC(1, 10, 12, 14);
const Mode Mode::ALPHANUMERIC(2,  9, 11, 13);
const Mode Mode::BYTE(4,  8, 16, 16);
const Mode Mode::KANJI(8,  8, 10, 12);
const Mode Mode::ECI(7,  0,  0,  0);

int Mode::getModeBits() const {
    return modeBits;
}

int Mode::numCharCountBits(int version) const {
    return numBitsCharCount[(version + 7) / 17];
}
