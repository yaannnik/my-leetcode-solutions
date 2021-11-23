/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty()) {
            return false;
        }
        set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            set<int>::iterator ite = s.lower_bound(max(nums[i], INT_MIN + t) - t);
            if(ite != s.end() && *ite <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            s.insert(nums[i]);
            if(i >= k) {
                s.erase(nums[i-k]);
            }
        }
        return false;
    }
};
// @lc code=end

