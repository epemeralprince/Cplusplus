#include <iostream>
#include <string>

class C1 {
private:
    std::string str;
public:
    C1() = delete;
    C1(std::string str) : str(str) { std::cout << "constructor with string" << std::endl; }
};

int main() {
    // C1* c1 = new C1();
    // 若是没有默认构造函数，则没有办法使用new创建类对象。

}