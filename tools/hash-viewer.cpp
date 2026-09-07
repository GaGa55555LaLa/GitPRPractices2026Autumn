#include "checker.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./hash-viewer ID" << std::endl;
        return -1;
    }

    std::cout << "Hash = " << HashString(argv[1]) << std::endl;
}