#include <iostream>
#include <string>

int main() {
    try {
        throw "error happened";
    }
    catch (const char* str) {
        std::cout << str << std::endl;
    }
    std::cout << "after catch block" << std::endl;
}