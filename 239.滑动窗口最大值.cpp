/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> qu;
        for(int i = 0; i < k; i++) {
            qu.emplace(nums[i], i);
        }
        vector<int> res = {qu.top().first};
        for(int i = k; i < n; i++) {
            qu.emplace(nums[i], i);
            while(qu.top().second <= i - k) {
                qu.pop();
            }
            res.emplace_back(qu.top().first);
        }
        return res;
    }
};
// @lc code=end

