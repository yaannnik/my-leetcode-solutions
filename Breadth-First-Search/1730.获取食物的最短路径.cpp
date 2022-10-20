#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int startx, starty, endx, endy;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '*') {
                    startx = i;
                    starty = j;
                    break;
                }
            }
        }

        queue<pair<int, int>> qu;
        qu.push({startx, starty});
        grid[startx][starty] = '-';
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int steps = 0;
        while(!qu.empty()) {
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                auto [x, y] = qu.front();
                qu.pop();
                for(int j = 0; j < 4; j++) {
                    int nx = x + dir[j][0], ny = y + dir[j][1];
                    if(nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                        if(grid[nx][ny] == '#') {
                            return steps + 1;
                        } else if(grid[nx][ny] == 'O') {
                            qu.push({nx, ny});
                            grid[nx][ny] = '-';
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
