#include "checker.h"

#include <iostream>

int main() {
    std::cout << "Starting main program...\n";

    if (HookRegistry::instance().runAll()) {
        std::cout << "LGTM.\n";
        return 0;
    } else {
        std::cout << "Oh My GOD, You break this project!!!\n";
        return 1;
    }
}