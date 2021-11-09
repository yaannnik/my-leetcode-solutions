/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTrack(nums, tmp, used);
        return res;
    }

    void backTrack(vector<int>& nums, 
                   vector<int>& tmp,
                   vector<bool>& used) {
        if(tmp.size() == nums.size()) {
            res.emplace_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if((used[i]) ||
               (i > 0 && 
                nums[i] == nums[i-1] && 
                !used[i-1])) {
                continue;
            }
            tmp.emplace_back(nums[i]);
            used[i] = true;
            backTrack(nums, tmp, used);

            tmp.erase(tmp.end()-1);
            used[i] = false;
        }
    }
};
// @lc code=end

