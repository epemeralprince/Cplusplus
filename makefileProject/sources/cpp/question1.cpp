#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0, m = 0;
    cin.get(); cin.get();
    cin >> m;
    cin.get(); cin.get(); cin.get();
    cin >> n;
    cout << "m = " << m << "  n = " << n << endl;
    vector<int> A(m+n, -1), B(n, -2);
    for (int i = 0; i < m; i++) {
        cin >> A[i];
        cin.get();
    }
    for (int i = 0; i < m; i++) {
        cout << A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        cin.get();
    }
    for (int i = 0; i < n; i++) {
        cout << B[i];
    }
    int r1 = m-1, r2 = n-1, index = m+n-1;
    while (r1 >= 0 || r2 >= 0) {
        if (r1 < 0 || (r2 >= 0 && A[r1] < B[r2])) {
            cout << "-----" << A[index] << "  " << B[r2] << endl;
            cout << "r2 == " << r2 << endl;
            A[index--] = B[r2--];
        } else if (r2 < 0 || (r1 >= 0 && A[r1] >= B[r2])) {
            cout << "+++++" << A[index] << "  " << A[r1] << endl;
            cout << "r1 == " << r1 << endl;
            A[index--] = A[r1--];
        }
        cout << A[index+1] << endl;
    }
    cout << "合并后的数组A" << endl;
    cout << "A = [";

    for (int i = 0; i < m+n; i++) {
        cout << A[i];
        if (i != m+n-1) {
            cout << ',';
        }
    }
    cout << "];" << endl;
}
