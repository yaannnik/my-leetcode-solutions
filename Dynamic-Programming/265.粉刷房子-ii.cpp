#include <vector>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> dp(2, vector<int>(k, 0));
        for(int i = 0; i < k; i++) {
            dp[1][i] = costs[0][i];
        }
        for(int i = 1; i < n; i++) {
            dp[0] = dp[1];

            for(int j = 0; j < k; j++) { // select j for i house
                int min_cost = INT_MAX;
                for(int j_ = 0; j_ < k; j_++) { // j_ for i-1 house, j != j_
                    if(j == j_) continue;
                    min_cost = min(min_cost, dp[0][j_]);
                }
                dp[1][j] = min_cost + costs[i][j];
            }
        }
        return *min_element(dp[1].begin(), dp[1].end());
    }
};
