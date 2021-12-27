/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> qu;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            long long dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            qu.emplace(-dist, i);
        }
        vector<vector<int>> res;
        while(k > 0) {
            auto tmp = qu.top();
            qu.pop();
            int idx = tmp.second;
            res.emplace_back(points[idx]);
            k--;
        }
        return res;
    }
};
// @lc code=end

