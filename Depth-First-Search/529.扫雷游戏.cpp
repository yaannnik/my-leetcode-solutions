#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int rows, cols;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        rows = board.size(), cols = board[0].size();
        int x = click[0], y = click[1];
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        } else {
            makeClick(board, x, y);
        }
        return board;
    }

    void makeClick(vector<vector<char>>& board, int x, int y) {
        // cout << x << " " << y << endl;
        if(x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'E') {
            return;
        }
        int bombs = 0;
        for(int i = 0; i < 8; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny] == 'M') {
                bombs++;
            }
        }
        if(bombs == 0) {
            board[x][y] = 'B';
            for(int i = 0; i < 8; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                makeClick(board, nx, ny);
            }
        } else {
            board[x][y] = '0' + bombs;
        }
    }
};
