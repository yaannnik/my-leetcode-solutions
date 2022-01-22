#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        // edge condition for s[0]
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            // if s[i] == '0', dp[i] = dp[i-2]
            dp[i + 1] = s[i] == '0' ? 0 : dp[i];
            if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6'))) {
                dp[i+1] += dp[i-1];
            }
        }
        return dp.back();
    }
};
