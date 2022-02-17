#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> path={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    vector<vector<vector<double>>> dp; // 保存(x, y)位置上走k步的结果（概率）
    double knightProbability(int n, int k, int row, int column) {
        dp = vector<vector<vector<double>>>(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        dfs(row, column, n, k);
        return dp[row][column][k];
    }

    double dfs(int x, int y, int n, int k) {
        if(k == 0) {
            dp[x][y][k] = 1.0;
            return dp[x][y][k];
        }
        if(dp[x][y][k] != -1) {
            return dp[x][y][k];
        }

        double p = 0;
        for(int i = 0; i < 8; i++) {
            int nx = x + path[i][0];
            int ny = y + path[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                continue;
            }
            p += 0.125 * dfs(nx, ny, n, k - 1);
        }
        dp[x][y][k] = p;
        return p;
    }
};
