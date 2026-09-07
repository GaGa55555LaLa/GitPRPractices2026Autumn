#include "checker.h"

static bool ID6() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("123000001", "Example student: I want to learn C++ and Git.");

    return isGoodVector(6, V);
}

REGISTER_HOOK(ID6);
