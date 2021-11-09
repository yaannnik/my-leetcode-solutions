/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());

        vector<int> tmp;
        backTrack(candidates, tmp, 0, 0, target);
        
        return res;
    }

    void backTrack(vector<int>& nums, 
                   vector<int>& tmp, 
                   int start, 
                   int sum, 
                   int target) {
        if(sum == target) {
            res.emplace_back(tmp);
            return;
        } else if (sum > target) {
            return;
        }
        for(int i = start; i < (int)nums.size(); i++) {
            tmp.emplace_back(nums[i]);
            backTrack(nums, tmp, i, sum+nums[i], target);

            tmp.erase(tmp.end()-1);
        }
    }
};
// @lc code=end

