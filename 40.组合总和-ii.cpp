/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> tmp;
        backTrack(candidates, tmp, 0, 0, target);

        return res;
    }

    void backTrack(vector<int>& nums,
                   vector<int>& tmp,
                   int start, int sum, int target) {
        if(sum == target) {
            res.emplace_back(tmp);
            return;
        } else if(sum > target) {
            return;
        }

        for(int i = start; i < (int)nums.size(); i++) {
            // 放在递归函数的for循环中，
            // 使得相同递归深度不会重复使用同样的数字，
            // [1,1,6]中的两个1不是在同一递归深度被添加的，所以可以
            if(i != start && nums[i] == nums[i-1]) {
                continue;
            }

            tmp.emplace_back(nums[i]);
            backTrack(nums, tmp, i+1, sum+nums[i], target);

            tmp.erase(tmp.end()-1);
        }
    }
};
// @lc code=end

