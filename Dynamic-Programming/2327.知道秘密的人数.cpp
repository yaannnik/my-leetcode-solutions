#include <vector>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        vector<long> dp(n + 1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int peopleNewShare = i > delay ? dp[i - delay] : 0;
            int peopleNewForget = i > forget ? dp[i - forget] : 0;
            dp[i] = (dp[i-1] + peopleNewShare - peopleNewForget + mod) % mod;
        }
        return (int)(dp[n] - dp[n - forget] + mod) % mod;
    }
};
