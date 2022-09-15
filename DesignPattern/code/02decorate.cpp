#include <iostream>


using namespace std;

class Interface {
public:
    virtual void function() = 0;
};

class Aclass : public Interface {
public:
    void function() {
        cout << "A function" << endl;
    }
};

class Bclass : public Interface {
public:
    void function() {
        cout << "B function" << endl;
    }
};

/*
拓展A和B类功能，使用继承的话，子类会越来越膨胀
这里从接口Interface继承出一个新的抽象基类。

*/

// 实现了Interface接口的抽象装饰类decorator
class newABC : public Interface {
protected:
    Interface* interImpl;
public:
    newABC(Interface* interInstance) : interImpl(interInstance) {}
    void function() {
        interImpl->function();  // 此时原来的基本功能已经能够完成了
    }
};

// 创建扩展了newABC类的实体装饰类decorator
class extendFunction : public newABC {
public:
    extendFunction(Interface* interInstance) : newABC(interInstance) {}
    void function() {
        cout << "new function1" << endl;
        interImpl->function();
        cout << "new function2" << endl;
    }
};


int main() {
    Aclass a;
    extendFunction ef(&a);
    ef.function();
}
