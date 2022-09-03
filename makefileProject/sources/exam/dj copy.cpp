#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> inNums;
    int i = 0;
    while(cin.peek()!='\n') {
        cin >> i;
        inNums.push_back(i);
    }
    if (inNums.size()==1) {
        return inNums[0];
    }

    vector<int> dp(inNums.size());
    dp[0] = inNums[0];
    dp[1] = max(inNums[0], inNums[1]);

    for (int i = 2; i < inNums.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + inNums[i]);
    }

    cout << dp[inNums.size()-1] << endl;

}



