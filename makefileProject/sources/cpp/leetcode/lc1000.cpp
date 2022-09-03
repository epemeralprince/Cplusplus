#include <vector>
#include <iostream>
#include <utility>

using namespace std;


class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size(), res = 0;
        vector<int> v1 = stones;
        if ((n-k)%(k-1)!=0)
            return -1;
        auto fun = [](vector<int>& stones, int k) -> pair<int, int> {
                int minSum = stones[0], minIndex = 0;
                for (int i = 1; i < k; i++) {
                    minSum += stones[i];
                }
                int curSum = minSum;
                cout << "minSum first = " << minSum << endl;
                for (int i = 1; i < stones.size()-k+1; i++) {
                    curSum = curSum - stones[i-1] + stones[i+k-1];
                    cout << "curSum = " << curSum << endl;
                    if (curSum < minSum) {
                        minIndex = i;
                        minSum = curSum;
                    }
                }
                return pair<int, int>(minIndex, minSum);
            };
        for (int i = 0; i < (n-k)/(k-1)+1; i++) {
            vector<int> v2(v1.size()-k+1);
            pair<int, int> ret = fun(v1, k);
            for (int j = 0; j < v2.size(); j++) {
                v2[j] = j > ret.first ? v1[j+k-1] : v1[j];
                if (j == ret.first) {
                    v2[j] = ret.second;
                }
            }
            cout << "v1: ";
            for (auto& val : v1)
                cout << val << " ";
            cout << endl;
            v1 = v2;
            cout << "v2: ";
            for (auto& val : v2)
                cout << val << " ";
            cout << endl;
            res += ret.second;
            cout << "res = " << res << endl;
        }
        return res;
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    cin >> k;
    Solution solution;
    int res = solution.mergeStones(stones, k);
    cout << "res = " << res << endl;
}

/*
4
3 2 4 1
2

4
3 2 4 1
3

5
3 5 1 2 6
3

4
6 4 4 6
2
*/