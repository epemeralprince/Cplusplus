#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int count = 1;
    int three = 0;
    vector<int> del(n, 1);
    while (count < n) {
        for (int i = 0; i < n; i++)
        {
            if (del[i]) {
                three++;
                cout << !three%3 << endl;
                if (three%3==0) {
                    del[i] = 0;
                    count++;
                    three = 0;
                }
            }
            cout << "i = " << i << "  three = " << three << endl;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (del[i])
            res = i+1;
    }
    cout << res << endl;
}
