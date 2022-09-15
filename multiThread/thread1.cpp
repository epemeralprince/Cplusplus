#define __cpp_lib_jthread

#include <iostream>
#include <thread>
#include <chrono>

void printn(int n, char ch) {
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << ch;
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{   
    std::jthread t0(&printn,  5, 'q');
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    //std::terminate();
    //t0.detach();
    std::cout << "main thread over" << std::endl;
    return 0;
}

