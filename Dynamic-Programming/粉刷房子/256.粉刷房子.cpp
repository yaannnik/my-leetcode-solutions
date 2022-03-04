#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(2, vector<int>(3, 0));
        dp[1][0] = costs[0][0];
        dp[1][1] = costs[0][1];
        dp[1][2] = costs[0][2];

        for(int i = 1; i < n; i++) {
            dp[0] = dp[1];
            // dp[i][j] = max(dp[i-1][!=j]) + costs[i][j]
            // dp[0] store i-1, dp[1] store i
            dp[1][0] = min(dp[0][1], dp[0][2]) + costs[i][0];
            dp[1][1] = min(dp[0][0], dp[0][2]) + costs[i][1];
            dp[1][2] = min(dp[0][0], dp[0][1]) + costs[i][2];
        }

        return min(dp[1][0], min(dp[1][1], dp[1][2]));
    }
};
