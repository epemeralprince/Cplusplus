#include <iostream>
#include <thread>
#include <mutex>

static bool sign = true;
static int pint = 7;

std::mutex mut;

void print(const char* str) {
    using namespace std::literals::chrono_literals;
    while (sign) {
        pint++;
        std::this_thread::sleep_for(1s);
        //mut.lock();
        
        std::cout << str << ", pint = " << pint << std::endl;
        
        //mut.unlock();
        pint--;
        std::this_thread::sleep_for(1s);

    }
}


int main() {

    std::thread t1(print, "thread 1");
    std::thread t2(print, "thread 2");

    int max_thread = t1.hardware_concurrency();
    std::cout << "max thread numbers: " << max_thread << std::endl;

    std::cout << t1.native_handle() << std::endl;


    std::thread::id id1 = t1.get_id();
    std::cout << "id = " << id1 << std::endl;
    std::thread::id id = t2.get_id();
    std::cout << "id = " << id << std::endl;

    std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;

    std::cin.get();
    //sign = false;
    t1.detach();
    t2.join();
    std::cout << "main thread end!!!" << std::endl;
}