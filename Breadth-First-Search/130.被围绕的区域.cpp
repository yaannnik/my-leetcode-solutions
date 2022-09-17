#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0, 1},{0, -1},{1, 0},{-1, 0}};
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        queue<pair<int, int>> qu;
        for(int i = 0; i < rows; i++) {
            if(board[i][0] == 'O') {
                qu.push({i, 0});
                board[i][0] = 'A';
            }
            if(board[i][cols-1] == 'O') {
                qu.push({i, cols-1});
                board[i][cols-1] = 'A';
            }
        }
        for(int i = 0; i < cols; i++) {
            if(board[0][i] == 'O') {
                qu.push({0, i});
                board[0][i] = 'A';
            }
            if(board[rows-1][i] == 'O') {
                qu.push({rows-1, i});
                board[rows-1][i] = 'A';
            }
        }

        while(!qu.empty()) {
            auto [x, y] = qu.front(); // 此处不能写引用
            // cout << x << " " << y << endl;
            qu.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny] == 'O') {
                    qu.push({nx, ny});
                    board[nx][ny] = 'A';
                }
            }

        }

        // cout << "here" << endl;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
