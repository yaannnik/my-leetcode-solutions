/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size() == 1) {
            return 0;
        }

        vector<int> cnts;
        int cnt = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                cnt++;
            } else {
                cnts.emplace_back(cnt);
                cnt = 1;
            }
        }
        cnts.emplace_back(cnt);
        int res = 0;
        if(cnts.size() == 1) {
            return 0;
        } else {
            for(int i = 1; i < cnts.size(); i++) {
                res += min(cnts[i-1], cnts[i]);
            }
        }
        return res;
    }
};
// @lc code=end

