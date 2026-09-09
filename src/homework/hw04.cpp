#include "checker.h"

static bool ID4() {
    Vec V;

    // Add your student ID and message here, in ascending student ID order.
    V.emplace_back("112062337", "teacher and TA are so handsome");
    V.emplace_back("123000003", "Example student: I want to learn C++ and Git.");

    return isGoodVector(4, V);
}

REGISTER_HOOK(ID4);
