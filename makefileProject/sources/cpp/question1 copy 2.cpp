#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> vi(n);
    for (int i = 0; i < n; i++) {
        cin >> vi[i];
    }
    sort(vi.begin(), vi.end(), greater<int>());
    for (int i = 0; i < vi.size(); i++) {
        cout << "i = " << i << "  vi[i] = " << vi[i] << endl;
    }
    int res = 0;
    int len = vi.size()%2==1?vi.size():vi.size()-1;
    for (int i = 0; i < len; i++) {
        int temp = vi[i]%2==1?vi[i]:vi[i]-1;
        res += temp;
    }
    cout << res << endl;
}
