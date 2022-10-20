class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) {
            return 0;
        }
        vector<vector<int>> dp;
        for(int i = 0; i < triangle.size(); i++) {
            int l = triangle.size();
            dp.emplace_back(l, 0);
        }

        for(int i = 0; i < triangle.size(); i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                if(i == 0) {
                    dp[i][j] = triangle[i][j];
                } else {
                    if(j == 0) {
                        dp[i][j] = triangle[i][j] + dp[i - 1][j];
                    } else if(j == triangle[i].size() - 1) {
                        dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                    }
                }
            }
        }

        int n = dp.size();
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
