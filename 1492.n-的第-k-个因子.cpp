/*
 * @lc app=leetcode.cn id=1492 lang=cpp
 *
 * [1492] n 的第 k 个因子
 */

// @lc code=start
class Solution {
public:
    int kthFactor(int n, int k) {
        int thres = sqrt(n);
        vector<int> l1, l2;
        for(int i = 1; i <= thres; i++) {
            if(n % i == 0) {
                l1.emplace_back(i);
                if(n/i != i) {
                    l2.emplace_back(n/i);
                } 
            }
        }
        int n1 = l1.size();
        int n2 = l2.size();
        if(k <= n1 + n2) {
            if(k <= n1) {
                return l1[k-1];
            } else {
                return l2[n2-(k-n1)];
            }
        }
        return -1;
    }
};
// @lc code=end

