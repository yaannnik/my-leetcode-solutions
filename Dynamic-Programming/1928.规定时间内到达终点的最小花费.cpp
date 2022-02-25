#include <vector>
using namespace std;

class Solution {
public:
    static constexpr int INFTY = INT_MAX / 2; // 防止加法溢出
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INFTY)); // f[t][i] 表示使用恰好 t 分钟到达城市 i 需要的最少通行费总和
        dp[0][0] = passingFees[0];

        for(int t = 1; t <= maxTime; t++) {
            for(auto& edge : edges) {
                int a = edge[0], b = edge[1], time = edge[2];
                if(time <= t) {
                    dp[t][a] = min(dp[t][a], dp[t-time][b] + passingFees[a]); // from b to a
                    dp[t][b] = min(dp[t][b], dp[t-time][a] + passingFees[b]); // from a to b
                }
            }
        }

        int res = INFTY;
        for(int t = 1; t <= maxTime; t++) {
            res = min(res, dp[t][n-1]);
        }
        return res == INFTY ? -1 : res;
    }
};
