/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) {
            return s;
        }
        int max_len = 1, begin = 0;
        for(int i = 0; i < n; i++) {
            auto p = expandHelper(s, i, i);
            if(p.second - p.first + 1 > max_len) {
                max_len = (p.second - p.first + 1);
                begin = p.first;
            }

            p = expandHelper(s, i, i+1);
            if(p.second - p.first + 1 > max_len) {
                max_len = (p.second - p.first + 1);
                begin = p.first;
            }
        }
        return s.substr(begin, max_len);
    }

    pair<int, int> expandHelper(string& s, int left, int right) {
        int n = s.size();
        while(left >= 0 && right <= n - 1 && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
};
// @lc code=end

