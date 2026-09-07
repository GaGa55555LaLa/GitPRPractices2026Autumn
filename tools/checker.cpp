#include "checker.h"

#include <iostream>

int main() {
    std::cout << "Starting main program...\n";

    if (HookRegistry::instance().runAll()) {
        std::cout << "\033[32mLGTM.\033[0m\n";
        return 0;
    } else {
        std::cout << "\033[31mOh My GOD, You break this project!!!\033[0m\n";
        return 1;
    }
}
