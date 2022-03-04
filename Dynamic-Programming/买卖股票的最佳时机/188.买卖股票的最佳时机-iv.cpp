#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k < 1) {
            return 0;
        }
        if(k >= prices.size()/2) {
            return greedy(prices);
        }

        vector<int> buyk(k, INT_MIN);
        vector<int> sellk(k, 0);

        for(int& price : prices) {
            buyk[0] = max(buyk[0], -price); // finish first buy
            sellk[0] = max(buyk[0] + price, sellk[0]); // finish first sell
            for(int i = 1; i < k; i++) {
                buyk[i] = max(sellk[i-1] - price, buyk[i]);
                sellk[i] = max(buyk[i] + price, sellk[i]);
            }
        }
        return sellk.back();
    }

    int greedy(vector<int>& prices) {
        int res = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1]) {
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};
