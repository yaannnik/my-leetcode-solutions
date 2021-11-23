/*
 * @lc app=leetcode.cn id=1915 lang=cpp
 *
 * [1915] 最美子字符串的数目
 */

// @lc code=start
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long> cnt(1024, 0);
        int mask = 0;
        long long res = 0;
        cnt[0] = 1;
        for(int i = 0; i < word.size(); i++) {
            mask ^= 1 << (word[i]-'a');
            res += cnt[mask];
            for(int j = 0; j < 10; j++) {
                res += cnt[mask ^ (1 << j)];
            }
            cnt[mask]++;
        }
        return res;
    }
};
// @lc code=end

