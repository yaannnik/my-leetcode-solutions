/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens(n, -1);
        unordered_set<int> columns;
        unordered_set<int> diags1, diags2;
        backTrack(res, queens, 0, n, columns, diags1, diags2);
        return res;
    }

    void backTrack(vector<vector<string>>& res, vector<int>& queens, int row, int n,
                   unordered_set<int>& columns, 
                   unordered_set<int>& diags1, 
                   unordered_set<int>& diags2) {
        if(row == n) {
            auto board = generateBoard(queens, n);
            res.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            int diag1 = row - col, diag2 = row + col;

            if(columns.find(col) != columns.end() ||
               diags1.find(diag1) != diags1.end() ||
               diags2.find(diag2) != diags2.end()) {
                   continue;
               }
            
            queens[row] = col; // 'Q' on (row, col)
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

    vector<string> generateBoard(vector<int>& queens, int n) {
        vector<string> board;
        
        for(auto& queen : queens) {
            string r(n, '.');
            r[queen] = 'Q';
            board.push_back(r);
        }

        return board;
    }
};
// @lc code=end

