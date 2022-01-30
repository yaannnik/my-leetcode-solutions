#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }
        for(int j = 0; j <= n; j++) {
            dp[m][j] = 0;
        }
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j]; // s[i]用于匹配t[j]或者不匹配，还用s[i+1:]里的去匹配
                } else {
                    dp[i][j] = dp[i+1][j]; // 用s[i+1:]里的去匹配
                }
            }
        }
        return dp[0][0];
    }
};
