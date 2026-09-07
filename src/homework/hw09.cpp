#include "checker.h"

static bool ID9() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("123000006", "Example student: I want to learn C++ and Git.");

    return isGoodVector(9, V);
}

REGISTER_HOOK(ID9);
