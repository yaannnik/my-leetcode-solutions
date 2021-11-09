/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> rows = vector<vector<bool>>(9, vector<bool>(9, false));
    vector<vector<bool>> cols = vector<vector<bool>>(9, vector<bool>(9, false));
    vector<vector<vector<bool>>> blocks = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));
    bool valid;
    vector<pair<int, int>> positions;
    //positions => [1 ~ 9, 1 ~ 9], all empty coordinates in the Sudoku
    void solveSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(board[row][col] == '.') {
                    positions.emplace_back(row, col);
                }
                else {
                    int digit = board[row][col] - '0' - 1;
                    rows[row][digit] = cols[col][digit] = blocks[row/3][col/3][digit] = true;
                }
            }
        }
        backTrack(board, 0);
    }

    void backTrack(vector<vector<char>>& board, int position) {
        if(position == positions.size()) {
            valid = true;
            return;
        }
        auto coordinate = positions[position];
        int row = coordinate.first;
        int col = coordinate.second;

        for(int digit = 0; digit < 9 && !valid; digit++) {
            // no two same digits in one row/col/block
            if(!rows[row][digit] && 
                !cols[col][digit] &&
                !blocks[row/3][col/3][digit]) {
                rows[row][digit] = true;
                cols[col][digit] = true;
                blocks[row/3][col/3][digit] = true;
                board[row][col] = '0' + (digit + 1);
                backTrack(board, position + 1);

                rows[row][digit] = false;
                cols[col][digit] = false;
                blocks[row/3][col/3][digit] = false;
            }
        }
    }
};
// @lc code=end

