#include <iostream>

using namespace std;

int main() {
    int leaf = 0, drop = 0, p = 0, Q = 0;
    cin >> leaf >> drop >> p >> Q;
    int i = 0;
    for (; leaf > 0; i++) {
        int month = i % 12 + 1;
        if (month >= p && month < p+Q) {
            leaf -= 2*drop;
        } else {
            leaf -= drop;
        }
        cout << "i = " << i << "  leaf = " << leaf << endl;
    }
    cout << i << endl;
}
