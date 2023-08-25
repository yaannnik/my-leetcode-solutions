#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> qu;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                } else if(grid[i][j] == 2) {
                    qu.emplace(i, j);
                }
            }
        }
        int min = 0;

        if(fresh == 0) {
            return min;
        }

        while(!qu.empty()) {
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                auto [x, y] = qu.front();
                qu.pop();
                grid[x][y] = 2;
                for(int j = 0; j < 4; j++) {
                    int nx = x + dir[j][0], ny = y + dir[j][1];
                    if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        qu.emplace(nx, ny);
                        grid[nx][ny] = 2;
                        fresh--;
                    }
                }
            }
            min++;
            if(fresh == 0) {
                return min;
            }
        }

        return -1;
    }
};
