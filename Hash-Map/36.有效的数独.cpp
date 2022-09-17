#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int cols[9][9];
        int boxes[3][3][9];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxes, 0, sizeof(boxes));

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    rows[i][idx]++;
                    cols[j][idx]++;
                    boxes[i/3][j/3][idx]++;
                    if(rows[i][idx] > 1 || cols[j][idx] > 1 || boxes[i/3][j/3][idx] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
