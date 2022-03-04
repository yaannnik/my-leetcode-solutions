#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2]; // "x*" is useless
                    if(match(s, p, i, j - 1)) {
                        dp[i][j] = dp[i][j] || dp[i-1][j]; // "x*" used for even once
                    }
                } else {
                    if(match(s, p, i, j)) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[m][n];
    }

    bool match(string& s, string& p, int i, int j) {
        if(i == 0 || j == 0) {
            return false;
        }
        if(p[j-1] == '.' || s[i-1] == p[j-1]) {
            return true;
        }
        return false;
    }
};
