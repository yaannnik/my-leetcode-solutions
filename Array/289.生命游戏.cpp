#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        board_ = board;
        int rows = board.size(), cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board_[i][j] == 1) {
                    aliveCell(i, j, rows, cols, board);
                } else {
                    deadCell(i, j, rows, cols, board);
                }
            }
        }
    }

    void aliveCell(int x, int y, int rows, int cols, vector<vector<int>>& board) {
        int alive = 0;
        for(int i = 0; i < 8; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                alive += board_[nx][ny];
            }
        }
        if(alive == 2 || alive == 3) {
            board[x][y] = 1;
        } else {
            board[x][y] = 0;
        }
        // cout << x << " " << y << " " << alive << endl;
    }

    void deadCell(int x, int y, int rows, int cols, vector<vector<int>>& board) {
        int alive = 0;
        for(int i = 0; i < 8; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                alive += board_[nx][ny];
            }
        }
        if(alive == 3) {
            board[x][y] = 1;
        } else {
            board[x][y] = 0;
        }
        // cout << x << " " << y << " " << alive << endl;
    }

    vector<vector<int>> board_;
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
};
