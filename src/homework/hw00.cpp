#include "checker.h"

static bool ID0() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("113062206", "hi");
    V.emplace_back("123000007", "Example student: I want to learn C++ and Git.");

    return isGoodVector(0, V);
}

REGISTER_HOOK(ID0);
