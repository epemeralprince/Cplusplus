#include <iostream>
#include <typeinfo>

using namespace std;


class A
{
private:
    int a;
public:
    A(int a = 9) : a(a) {}
    A(const A& a) : a(a.a) { 
        a.fff();
        cout << "A copy constructor" << endl; 
    }
    virtual void fff() const {
        cout << "a = " << a << endl;
    }
};

class B : public A
{
private:
    double b;
public:
    B(double b = 4.3) : b(b) {}
    B(int a, double b = 4.3) : A(a), b(b) {}
private:
    void fff() {
        cout << "b fff()" << endl;
        A::fff();
        cout << "b = " << b << endl;
    }
};

void fun(A a) {
    cout << "fun()" << endl;
    cout << typeid(a).name() << endl;
}


int main() {
    //A* a = new B();  
    // 只有继承方式为public才能用父类指针指向子类对象

    B b;
    fun(b);
    A a = b;
    a.fff();
    cout << "--------" << endl;
    const A* aa = new B;
    aa->fff();
    A& aaa = b;
    aaa.fff();
}