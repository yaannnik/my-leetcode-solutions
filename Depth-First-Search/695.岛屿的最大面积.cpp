#include <vector>
using namespace std;

class Solution {
public:
    int rows, cols;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int res = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    res = max(res, getSize(i, j, grid));
                }
            }
        }
        return res;
    }

    int getSize(int x, int y, vector<vector<int>>& grid) {
        int size = 1;
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                size += getSize(nx, ny, grid);
            }
        }
        return size;
    }
};
