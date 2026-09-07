#include "checker.h"

static bool ID7() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("123000008", "Example student: I want to learn C++ and Git.");

    return isGoodVector(7, V);
}

REGISTER_HOOK(ID7);
