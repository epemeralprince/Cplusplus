#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Bin {
public:
    int l, w, h;
    Bin() {}
    Bin(int l, int w, int h) : l(l), w(w), h(h) {}
    bool operator>(const Bin& bin) const {
        if (l > bin.l && w > bin.w) {
            return true;
        } else 
            return false;
    }
    bool operator<(Bin& bin) const {
        if (l < bin.l && w < bin.w) {
            return true;
        } else 
            return false;
    }
    bool operator==(Bin& bin) const {
        if (l == bin.l && w == bin.w) {
            return true;
        } else 
            return false;
    }
};


int main() {
    int n = 0;
    cin >> n;
    vector<Bin> bins(n);
    int res = 0;
    int t1, t2, t3;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2 >> t3;
        bins.emplace_back(t1, t2, t3);
    }
    sort(bins.begin(), bins.end(), greater<Bin>());
    for (int i = 0; i < bins.size(); i++) {
        if (bins[i] > bins[i+1]) {
            res += bins[i].h;
        } else {
            int maxh = bins[i].h;
            int j = i;
            while (j < bins.size()-1 && !(bins[j] > bins[j+1])) {
                maxh = max(maxh, bins[j+1].h);
            }
            i = j-1;
            res += maxh;
            if (j >= bins.size()-1)
                break;
        }
    }
    cout << res << endl;
}

/*
3
1 1 1
2 2 2
1 2 4

4
*/
