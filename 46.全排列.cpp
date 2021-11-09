/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
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
            if(used[i]) {
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

