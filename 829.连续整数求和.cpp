/*
 * @@author: yangyi
 */
/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 0;
        
        for(int i = 0; n > 0; n -= i) {
            if(n % (++i) == 0) {
                res++;
            }
            
        }
        
        return res;
    }
};
// @lc code=end

