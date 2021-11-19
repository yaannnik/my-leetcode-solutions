/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        for(const auto& i : nums) {
            mp[i]++;
        }
        for(const auto& m : mp) {
            if(k == 0) {
                res += (m.second > 1) ? 1 : 0;
            } else {
                res += mp.count(m.first + k);
            }
        }
        return res;
    }
};
// @lc code=end

