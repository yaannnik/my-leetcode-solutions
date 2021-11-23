/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for(int i = 0; i < citations.size(); i++) {
            int h = citations.size() - i;
            if(citations[i] >= h) {
                return h;
            }
        }
        return 0;
    }

    bool static cmp(int& a, int& b) {
        return (a > b);
    }
};
// @lc code=end

