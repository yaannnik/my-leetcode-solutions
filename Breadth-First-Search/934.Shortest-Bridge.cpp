#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        bool found = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid);
                    found = true;
                    break;
                }
            }
            if(found) {
                break;
            }
        }
        queue<pair<int, int>> qu;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    qu.emplace(i, j);
                }
            }
        }
        int step = 0;
        while(!qu.empty()) {
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                auto [x, y] = qu.front();
                qu.pop();
                for(int j = 0; j < 4; j++) {
                    int nx = x + dir[j][0], ny = y + dir[j][1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 1) {
                        continue;
                    }
                    if(grid[nx][ny] == 2) {
                        return step;
                    }
                    if(grid[nx][ny] != 1) {
                        grid[nx][ny] = 1;
                        qu.emplace(nx, ny);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    void dfs(int x, int y, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) {
            return;
        }
        grid[x][y] = 2;
        dfs(x - 1, y, grid);
        dfs(x + 1, y, grid);
        dfs(x, y - 1, grid);
        dfs(x, y + 1, grid);
    }
};
