/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int len = s.size();
        int r = -1, res = 0;
        for(int l = 0; l < len; l++) {
            if(l != 0) {
                chars.erase(s[l - 1]);
            }
            while(r + 1 < len && chars.count(s[r + 1]) == 0) {
                chars.insert(s[r + 1]);
                r++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end

