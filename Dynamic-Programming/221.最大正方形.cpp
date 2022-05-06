#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int max_side = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(matrix[row][col] == '0') continue;
                else {
                    if(row == 0 || col == 0) {
                        dp[row][col] = 1;
                    } else {
                        dp[row][col] = min(dp[row-1][col], min(dp[row][col-1], dp[row-1][col-1]))+1;
                    }
                    max_side = max(max_side, dp[row][col]);
                }
            }
        }
        return max_side * max_side;
    }
};
