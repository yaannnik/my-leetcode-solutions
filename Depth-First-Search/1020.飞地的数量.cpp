#include <vector>
using namespace std;

class Solution {
public:
    int m, n;
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j, visited, grid);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y]) {
            return;
        }
        visited[x][y] = true;
        vector<int> dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            dfs(nx, ny, visited, grid);
        }
    }
};
