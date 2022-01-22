#include <vector>
using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<int> degree(n, 0);

        for(auto& e : edges) {
            int u = e[0], v = e[1];

            adj[u-1].emplace_back(v);
            adj[v-1].emplace_back(u);

            mat[u-1][v-1] = 1;
            mat[v-1][u-1] = 1;

            degree[u-1]++;
            degree[v-1]++;
        }

        int res = INT_MAX;
        for(int a = 1; a <= n; a++) {
            int l = adj[a-1].size();
            for(int i = 0; i < l - 1; i++) {
                for(int j = i + 1; j < l; j++) {
                    int b = adj[a-1][i], c = adj[a-1][j];
                    if(mat[b-1][c-1] == 1) {
                        // a-b-c is a trio
                        res = min(res, degree[a-1] + degree[b-1] + degree[c-1] - 6);
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
