/*
 * @lc app=leetcode.cn id=1648 lang=cpp
 *
 * [1648] 销售价值减少的颜色球
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size();
        sort(inventory.begin(), inventory.end(), cmp);
        vector<long long> diff = vector<long long>(n);
        long long left = orders;
        long long res = 0;
        for(int i = 0; i < n; i++) {
            if(i < n - 1) {
                diff[i] = inventory[i] - inventory[i+1];
            } else {
                diff[i] = inventory[i];
            }
            int batch = i + 1;
            if(left > diff[i] * batch) {
                res += (inventory[i]*diff[i] - (diff[i]*(diff[i]-1))/2) * batch;
                res = (res % (long long)(1e9+7));
                left -= diff[i] * batch;
            } else {
                long long times = left / (i + 1);
                res += (inventory[i]*times - (times*(times-1))/2) * batch;
                res += (inventory[i]-times) * (left - times*batch);
                res = (res % (long long)(1e9+7));
                return res;
            }
        }
        return -1;
    }

    bool static cmp(int& a, int& b) {
        return (a > b);
    }
};
// @lc code=end

