#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> qu;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    qu.emplace(i, j);
                    seen[i][j] = true;
                }
            }
        }
        while(!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx][ny]) {
                    qu.emplace(nx, ny);
                    dist[nx][ny] = dist[x][y] + 1;
                    seen[nx][ny] = true;
                }
            }
        }
        return dist;
    }
};
