#include "checker.h"
#include <cstdint>
#include <string>
#include <string_view>

std::size_t HashString(const std::string &S) {
    // FNV-1a: XOR each byte, then multiply with unsigned 32-bit wraparound.
    std::uint32_t Hash = 2166136261u;
    for (unsigned char Byte : S) {
        Hash ^= Byte;
        Hash *= 16777619u;
    }
    return Hash % 10;
}

bool isGoodVector(std::size_t E, const Vec &V) {
    std::string_view LastID;

    for (auto &[ID, _] : V) {
        if (HashString(ID) != E)
            return false;
        if (LastID >= ID)
            return false;
        LastID = ID;
    }

    return true;
}
