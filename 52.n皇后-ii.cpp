/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> queens(n, -1);
        unordered_set<int> columns;
        unordered_set<int> diags1, diags2;
        backTrack(res, queens, 0, n, columns, diags1, diags2);
        return res;
    }

    void backTrack(int& res, vector<int>& queens, int row, int n,
                   unordered_set<int>& columns, 
                   unordered_set<int>& diags1, 
                   unordered_set<int>& diags2) {
        if(row == n) {
            res += 1;
            return;
        }

        for(int col = 0; col < n; col++) {
            int diag1 = row - col, diag2 = row + col;
            if(columns.find(col) != columns.end() || 
               diags1.find(diag1) != diags1.end() ||
               diags2.find(diag2) != diags2.end()) {
                   continue;
               }
            
            queens[row] = col;
            columns.insert(col);
            diags1.insert(diag1);
            diags2.insert(diag2);
            backTrack(res, queens, row+1, n, columns, diags1, diags2);

            queens[row] = -1;
            columns.erase(col);
            diags1.erase(diag1);
            diags2.erase(diag2);
        }
    }
};
// @lc code=end

