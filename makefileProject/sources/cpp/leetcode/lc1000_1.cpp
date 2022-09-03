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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(k+1, INT_MAX)));
        for (int i = 0; i <= n; i++) {
            dp[i][i][1] = 0;
        }
        vector<int> sum(n+1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i-1] + stones[i-1];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i+len-1 <= n; i++) {
                int j = i+len-1;
                for (int m = 2; m <= len; m++) {
                    cout << "=========================" << endl;
                    cout << "m === " << m << endl;
                    for (int cp = i; cp < j; cp += k-1) {
                        dp[i][j][m] = min(dp[i][j][m], dp[i][cp][1] + dp[cp+1][j][m-1]);
                        cout << "dp[" << i << "][" << j << "][" << m << "] = " << dp[i][j][m] << endl;
                    }
                }
                dp[i][j][1] = dp[i][j][k] + sum[j] - sum[i-1];
                cout << "dp[" << i << "][" << j << "][" << 1 << "] ----> " << dp[i][j][1] << endl;

            }
        }
        cout << endl << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int b = 1; b <= k; b++) {
                    cout << "dp[" << i << "][" << j << "][" << b << "] = " << dp[i][j][b] << "  ";
                }
                cout << endl;
            }
            cout << endl;
        }
        return dp[1][n][1];
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