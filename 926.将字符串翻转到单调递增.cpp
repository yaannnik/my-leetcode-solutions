/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0;
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                cnt0++;
            }
            if(s[i] == '1') {
                cnt1++;
            }
            if(cnt0 > cnt1) {
                res += cnt1;
                cnt0 = 0;
                cnt1 = 0;
            }
        }
        return res + cnt0;
    }
};
// @lc code=end

