#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int l = longestCommonSubsequence(word1, word2);
        return m + n - 2 * l;
    }

    int longestCommonSubsequence(string& word1, string& word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(word1[i] == word2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
