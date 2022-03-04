#include <vector>
using namespace  std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for(int& price : prices) {
            buy1 = max(buy1, -price); // i-th finish first buy
            sell1 = max(buy1 + price, sell1); // i-th finish second buy
            buy2 = max(buy2, sell1 - price); // i-th finish second buy
            sell2 = max(sell2, buy2 + price); // i-th finish second sell
        }
        return max(sell1, sell2);
    }
};
