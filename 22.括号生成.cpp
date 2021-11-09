/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        backTrack(res, temp, 0, 0, n);
        return res;
    }

    void backTrack(vector<string>& res, string& temp, 
                    int left, int right, int n) {
        if(temp.size() == 2 * n) {
            res.push_back(temp);
            return;
        }
        if(left < n) {
            temp.push_back('(');
            backTrack(res, temp, left + 1, right, n);
            temp.pop_back();
        }
        if(right < left) {
            temp.push_back(')');
            backTrack(res, temp, left, right + 1, n);
            temp.pop_back();
        }
    }
};
// @lc code=end

