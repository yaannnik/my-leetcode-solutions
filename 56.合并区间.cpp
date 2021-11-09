/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if(res.empty() || res.back()[1] < start) {
                res.push_back({start, end});
            } else {
                res.back()[1] = max(res.back()[1], end);
            }
        }
        return res;
    }
};
// @lc code=end

