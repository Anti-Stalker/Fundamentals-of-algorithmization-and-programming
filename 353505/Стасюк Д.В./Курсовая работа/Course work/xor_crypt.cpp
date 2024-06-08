#include "xor_crypt.h"

std::string xor_crypt(std::string key, std::string data) {
    std::string result = "";
    for (size_t i = 0; i < data.length(); i++)
    {
        result += data[i] ^ key[i%key.length()];
    }
    return result;
}

