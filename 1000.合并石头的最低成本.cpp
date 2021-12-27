/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1) != 0) return -1;
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
        }
        vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(K + 1, 0x3f3f3f3f)));
        for (int i = 0; i < n; ++i) {
            f[i][i][1] = 0;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                for (int k = 2; k <= K; ++k) {
                    for (int m = i; m < j; m += K - 1) {
                        f[i][j][k] = min(f[i][j][k], f[i][m][1] + f[m + 1][j][k - 1]);
                    }
                }
                f[i][j][1] = f[i][j][K] + prefix[j + 1] - prefix[i];
            }
        }
        return f[0][n - 1][1];        
    }
};
// @lc code=end

