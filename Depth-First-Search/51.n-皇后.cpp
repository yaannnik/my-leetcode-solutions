#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos;
        unordered_set<int> columns, diag1, diag2;
        dfs(n, 0, pos, columns, diag1, diag2);
        return res;
    }

    void dfs(int n, int row, vector<int>& pos,
             unordered_set<int>& columns,
             unordered_set<int>& diag1,
             unordered_set<int>& diag2) {
        if(row == n) {
            auto board = makeBoard(n, pos);
            res.emplace_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {

            if(columns.find(col) != columns.end() ||
               diag1.find(row-col) != diag1.end() ||
               diag2.find(row+col) != diag2.end()) {
                continue;
            }

            columns.insert(col);
            diag1.insert(row-col);
            diag2.insert(row+col);
            pos.emplace_back(col);

            dfs(n, row+1, pos, columns, diag1, diag2);

            pos.erase(pos.end()-1);
            diag2.erase(row+col);
            diag1.erase(row-col);
            columns.erase(col);

        }
    }

    vector<string> makeBoard(int n, vector<int>& pos) {
        vector<string> board;
        for(int i = 0; i < n; i++) {
            string line(n, '.');
            line[pos[i]] = 'Q';
            board.emplace_back(line);
        }

        return board;
    }
};