#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for(int r = 0; r < rows; r++) {
            if(obstacleGrid[r][0] == 1) {
                break;
            }
            dp[r][0] = 1;
        }
        for(int c = 0; c < cols; c++) {
            if(obstacleGrid[0][c] == 1) {
                break;
            }
            dp[0][c] = 1;
        }

        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                if(obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[rows-1][cols-1];
    }
};
