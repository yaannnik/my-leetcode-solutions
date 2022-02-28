#include <vector>
using namespace std;

class Solution1 {
public:
    const long mod = 1e9 + 7;
    int knightDialer(int n) {
        if(n == 1) {
            return 10;
        }
        long n1379 = 4, n46 = 2, n28 = 2, n0 = 1;
        for(int i = 0; i < n - 1; i++) {
            int n1379_ = (2 * n46 + 2 * n28) % mod;
            int n46_ = (n1379 + n0 * 2) % mod;
            int n28_ = n1379 % mod;
            int n0_ = n46 % mod;

            n1379 = n1379_;
            n46 = n46_;
            n28 = n28_;
            n0 = n0_;
        }
        int res = (n1379 + n46) % mod;
        res = (res + n28) % mod;
        res = (res + n0) % mod;
        return res;
    }
};

class Solution2 {
public:
    const long mod = 1e9 + 7;
    int knightDialer(int n) {
        vector<vector<int>> move = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        vector<long> dp(10, 1);
        for(int i = 0; i < n - 1; i++) { // n - 1 jumps
            vector<long> dp2(10, 0);
            for(int k = 0; k < 10; k++) {
                for(int& target : move[k]) {
                    dp2[target] += dp[k];
                    dp2[target] %= mod;
                }
            }
            dp = dp2;
        }
        int res = 0;
        for(int i = 0; i < 10; i++) {
            res += dp[i];
            res %= mod;
        }
        return res;
    }
};
