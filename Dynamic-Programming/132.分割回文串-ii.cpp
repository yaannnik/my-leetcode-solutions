#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> isPalindrome(n, vector<int>(n, true));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }

        vector<int> dp(n, INT_MAX);
        for(int i = 0; i < n; i++) {
            if(isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                for(int j = 0; j < i; j++) {
                    if(isPalindrome[j+1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
