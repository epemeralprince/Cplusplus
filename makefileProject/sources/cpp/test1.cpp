#include "utils.h"
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class A {
public:
    A() {
        cout << "A constructor execte" << endl;
    }
};

int main(int argc, char* argv[]) {
    string a = "etg";
    string b = "kdj";
    swap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int c = 5;

    int d = 9;
    ::swap(c, d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    
    vector<A> va;
    va.reserve(11);
}