#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while(!checkCrush(board)) {
            continue;
        }
        return board;
    }

    bool checkCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> mark(m, vector<int>(n));
        bool clear = true; // check if there are candies to crush

        for(int i = 0; i < m; i++) {
            int j = 0;
            while(j < n) {
                if(board[i][j] == 0) {
                    ++j;
                    continue;
                }
                int jj = j;
                while(jj < n && board[i][jj] == board[i][j]) {
                    jj++;
                }
                if(jj - j >= 3) {
                    for(int k = j; k < jj; k++) {
                        mark[i][k] = 1;
                    }
                    clear = false;
                }
                j = jj;
            }
        }

        for(int j = 0; j < n; j++) {
            int i = 0;
            while(i < m) {
                if(board[i][j] == 0) {
                    i++;
                    continue;
                }
                int ii = i;
                while(ii < m && board[ii][j] == board[i][j]) {
                    ii++;
                }
                if(ii - i >= 3) {
                    for(int k = i; k < ii; k++) {
                        mark[k][j] = 1;
                    }
                    clear = false;
                }
                i = ii;
            }
        }

        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                if(mark[i][j] == 1) {
                    cnt++;
                    board[i][j] = 0;
                }
            }
            if(cnt > 0) {
                int bottom = m - 1; // bottom to fall
                for(int i = m - 1; i >= 0; i--) {
                    if(board[i][j] != 0) {
                        board[bottom][j] = board[i][j];
                        if(bottom != i) {
                            // vacant space
                            board[i][j] = 0;
                        }
                        bottom--;
                    }
                }
            }
        }
        return clear;
    }
};
