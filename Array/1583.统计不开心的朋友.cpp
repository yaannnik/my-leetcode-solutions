#include <vector>
using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> rank(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1; j++) {
                rank[i][preferences[i][j]] = j;
            }
        }
        vector<int> match(n);
        for(auto& pair : pairs) {
            match[pair[0]] = pair[1];
            match[pair[1]] = pair[0];
        }

        int res = 0;
        for(int x = 0; x < n; x++) {
            int y = match[x];
            int idx = rank[x][y];
            for(int i = 0; i < idx; i++) {
                // 穷举所有亲近程度胜过y的u
                int u = preferences[x][i];
                int v = match[u];
                if(rank[u][x] < rank[u][v]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
