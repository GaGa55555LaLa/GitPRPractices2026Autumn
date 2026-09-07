#include "checker.h"

static bool ID1() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("123000004", "Example student: I want to learn C++ and Git.");

    return isGoodVector(1, V);
}

REGISTER_HOOK(ID1);
