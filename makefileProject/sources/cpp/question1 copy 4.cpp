#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
    int nums = 0;
    int maxdis = 0;
public:
    vector<int> solve(vector<vector<int>>& graph) {
        vector<vector<int>> did(graph.size(), vector<int>(graph[0].size(), 1));
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[0].size(); j++) {
                if (graph[i][j] && did[i][j]) {
                    vector<pair<int, int>> local;
                    dfs(graph, did, local, i, j);
                    nums++;
                    cout << "nums = " << nums << endl;
                    for (int ig = 0; ig < local.size(); ig++) {
                        cout << "ig = " << ig << "  x = " << local[ig].first << "  y = " << local[ig].second << endl;
                    }
                    for (int k = 0; k < local.size(); k++) { 
                        for (int kk = 1; kk < local.size(); kk++) {
                            maxdis = max(maxdis, abs(local[k].first-local[kk].first) + abs(local[k].second-local[kk].second));
                        }
                    }
                    cout << "maxdis = " << maxdis << endl;
                }
            }
        }
        return {nums, maxdis};
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& did, vector<pair<int, int>>& local, int i, int j) {
        did[i][j] = 0;
        local.emplace_back(i, j);
        if (i-1 >= 0 && did[i-1][j] && graph[i-1][j]) {
            dfs(graph, did, local, i-1, j);
        }
        if (j-1 >= 0 && did[i][j-1] && graph[i][j-1]) {
            dfs(graph, did, local, i, j-1);
        }
        if (i+1 < graph.size() && did[i+1][j] && graph[i+1][j]) {
            dfs(graph, did, local, i+1, j);
        }
        if (j+1 < graph[0].size() && did[i][j+1] && graph[i][j+1]) {
            dfs(graph, did, local, i, j+1);
        }
        return;
    }

};


int main() {
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<int>> graph(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    Solution solution;
    vector<int> res = solution.solve(graph);
    cout << res[0] << "  " << res[1] << endl;
}

/*
8 10
0 0 0 0 0 1 1 1 1 1
0 1 0 0 0 1 0 0 0 1
0 0 0 0 0 1 0 0 0 1
0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 1 1 1 1 1 0 0
1 1 1 1 1 1 1 1 1 0

[3, 8]
*/
