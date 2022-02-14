#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mask;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if (grid[row][col] == color) {
            return grid;
        }
        int m = grid.size(), n = grid[0].size();
        mask = vector<vector<int>>(m, vector<int>(n, 0));
        int val = grid[row][col];
        dfs(row, col, val, color, grid);
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(mask[i][j] == 1 && mask[i - 1][j] == 1 && mask[i + 1][j] == 1 && mask[i][j - 1] == 1 && mask[i][j + 1] == 1) {
                    grid[i][j] = val;
                }
            }
        }
        return grid;
    }

    void dfs(int x, int y, int val, int color, vector<vector<int>>& grid) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != val || mask[x][y] == 1) {
            return;
        }
        grid[x][y] = color;
        mask[x][y] = 1;
        vector<int> dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            dfs(nx, ny, val, color, grid);
        }
    }
};
