#include <vector>
using namespace std;

class Solution {
public:
    vector<int> res;
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        res = vector<int>(n, -1);
        for(int i = 0; i < n; i++) {
            dfs(grid, -1, i, i);
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int idx) {
        // cout << row << ", " << col << endl;
        if(row == (int)grid.size() - 1) {
            // cout << "here" << endl;
            res[idx] = col;
            return;
        }
        if(row + 1 < grid.size() && col + 1 < grid[0].size() && grid[row+1][col] == 1 && grid[row+1][col+1] == 1) {
            dfs(grid, row+1, col+1, idx);
            return;
        }
        if(row + 1 <= grid.size() && col - 1 >= 0 && grid[row+1][col-1] == -1 && grid[row+1][col] == -1) {
            dfs(grid, row+1, col-1, idx);
            return;
        }
        return;
    }
};
