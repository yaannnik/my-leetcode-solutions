#include <vector>
using namespace std;

class Solution {
public:
    int res;
    vector<vector<bool>> matrix;

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        matrix = vector<vector<bool>>(m + 2, vector<bool>(n + 2, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    matrix[i+1][j+1] = true;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    backtrack(i, j, 0, grid);
                }
            }
        }
        return res;
    }

    void backtrack(int i, int j, int tmp, vector<vector<int>>& grid) {
        int x = i + 1, y = j + 1;
        tmp += grid[i][j];
        matrix[x][y] = false;
        if(!matrix[x-1][y] && !matrix[x+1][y] && !matrix[x][y-1] && !matrix[x][y+1]) {
            matrix[x][y] = true; // return的情况下也要记得还原
            res = max(res, tmp);
            return;
        }
        if(matrix[x-1][y]) {
            backtrack(i - 1, j, tmp, grid);
        }
        if(matrix[x+1][y]) {
            backtrack(i + 1, j, tmp, grid);
        }
        if(matrix[x][y-1]) {
            backtrack(i, j - 1, tmp, grid);
        }
        if(matrix[x][y+1]) {
            backtrack(i, j + 1, tmp, grid);
        }
        matrix[x][y] = true;
    }
};
