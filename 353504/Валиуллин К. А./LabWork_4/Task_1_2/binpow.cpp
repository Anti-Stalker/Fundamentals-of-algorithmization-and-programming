#include "binpow.h"

Binpow::Binpow() {}

long long Binpow::binpow(long long digit, long long powder, long long mod)
{
    digit %= mod;
    long long result = 1;
    while (powder) {
        if (powder & 1) {
            result = (result * digit) % mod;
        }
        digit = (digit * digit) % mod;
        powder >>= 1;
    }
    return result;
}
