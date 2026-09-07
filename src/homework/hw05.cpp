#include "checker.h"

static bool ID5() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("123000000", "Example student: I want to learn C++ and Git.");

    return isGoodVector(5, V);
}

REGISTER_HOOK(ID5);
