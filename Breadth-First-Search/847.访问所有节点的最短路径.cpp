#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int,int,int>> qu;
        vector<vector<int>> visited(n, vector<int>(1 << n));
        for(int i = 0; i < n; i++) {
            qu.emplace(i, 1 << i, 0);
            visited[i][1 << i] = true; // 以i为起点
        }

        while(!qu.empty()) {
            auto [u, mask, dist] = qu.front();
            qu.pop();
            if(mask == (1 << n) - 1) {
                return dist; // 访问完所有点
            }
            for(int& v : graph[u]) {
                int mask_v = mask | (1 << v);
                if(!visited[v][mask_v]) {
                    qu.emplace(v, mask_v, dist + 1);
                    visited[v][mask_v] = true;
                }
            }
        }
        return -1;
    }
};
