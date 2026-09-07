#include "checker.h"

static bool ID8() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("123000009", "Example student: I want to learn C++ and Git.");

    return isGoodVector(8, V);
}

REGISTER_HOOK(ID8);
