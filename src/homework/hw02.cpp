#include "checker.h"

static bool ID2() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("114062328", "老師請問可以等四年讓我碩士讀完嗎");
    V.emplace_back("123000005", "Example student: I want to learn C++ and Git.");

    return isGoodVector(2, V);
}

REGISTER_HOOK(ID2);
