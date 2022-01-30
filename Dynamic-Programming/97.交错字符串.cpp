#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if(m + n != k) {
            return false;
        }
        // 表示 s_1的前 i 个元素和 s_2的前 j 个元素是否能交错组成 s_3的前 i + j 个元素
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                int p = i + j - 1;
                if(i > 0) {
                    dp[i][j] = dp[i][j] || (dp[i-1][j] && s1[i-1] == s3[p]); // 用s1的i来补
                }
                if(j > 0) {
                    dp[i][j] = dp[i][j] || (dp[i][j-1] && s2[j-1] == s3[p]); // 用s2的j来补
                }
            }
        }
        return dp[m][n];
    }
};
