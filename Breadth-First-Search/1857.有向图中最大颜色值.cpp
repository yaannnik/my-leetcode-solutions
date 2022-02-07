#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), m = edges.size();
        vector<int> degree(n, 0);
        vector<vector<int>> target(n);
        for(vector<int>& edge : edges) {
            degree[edge[1]]++;
            target[edge[0]].emplace_back(edge[1]);
        }
        int cnt = 0;
        queue<int> qu;
        vector<vector<int>> f(n, vector<int>(26, 0)); // 以节点v为终点的所有路径中，包含颜色c的节点数量的最大值
        for(int i = 0; i < n; i++) {
            if(degree[i] == 0) {
                qu.push(i);
            }
        }
        while(!qu.empty()) {
            int u = qu.front();
            qu.pop();
            cnt++;
            f[u][colors[u]-'a']++;
            for(int& v : target[u]) {
                degree[v]--;
                if(degree[v] == 0) {
                    qu.push(v);
                }
                for(int c = 0; c < 26; c++) {
                    f[v][c] = max(f[v][c], f[u][c]); // 和前序节点比较，找到c对应的最大值
                }
            }
        }
        if(cnt != n) {
            return -1; // 没有遍历完所有节点
        }

        int res = 0;
        for(auto& tmp : f) {
            res = max(res, *max_element(tmp.begin(), tmp.end()));
        }
        return res;
    }
};
