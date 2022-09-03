#include <iostream>
#include <string>

using namespace std;


class Solution {
    int res = 0;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 查找"iflytek"子串
     * @param str string字符串 输入字符串
     * @return int整型
     */
    int findIflytek(string str) {
        // write code here
        string target = "iflytek";
        dfs(str, target, 0, 0);
        return res;
    }
    
    void dfs(string& str, string& target, int pos, int tp) {
        for (int i = pos; i < str.size(); i++) {
            if (str[i] == target[tp] && tp == target.size()-1) {
                res++;
            } else if (str[i] == target[tp]) {
                dfs(str, target, i+1, tp+1);
            }
        }
    }
};


int main() {
    int value = 0;
    int &a = value;
    a = 5;
    decltype(a) b = value;
    b = 10;
    cout << value << endl;
}