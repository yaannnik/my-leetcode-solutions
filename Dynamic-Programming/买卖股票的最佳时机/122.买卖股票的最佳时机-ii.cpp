#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp1[i]: i-th with stock, dp2[i]: i-th without stock
        vector<int> dp1(n, -prices[0]), dp2(n, 0);
        for(int i = 1; i < n; i++) {
            dp1[i] = max(dp1[i-1], dp2[i-1] - prices[i]);
            dp2[i] = max(dp1[i-1] + prices[i], dp2[i-1]);
        }
        return dp2.back();
    }
};
