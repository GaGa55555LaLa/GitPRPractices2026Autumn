#include "checker.h"

static bool ID3() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("123000002", "Example student: I want to learn C++ and Git.");

    return isGoodVector(3, V);
}

REGISTER_HOOK(ID3);
