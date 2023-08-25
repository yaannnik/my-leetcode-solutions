#include <vector>
#include <queue>
using namespace std;

struct state {
    int x;
    int y;
    int r;
    state(int x_, int y_, int r_) : x(x_), y(y_), r(r_) {}
};

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if(m == 1 && n == 1) {
            return 0;
        }

        k = min(k, m + n - 3); // m + n - 1 - 2 obstacles at most

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<state> qu;
        qu.emplace(0, 0, k);
        visited[0][0][k] = true;

        int res = 0;

        while(!qu.empty()) {
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                state s = qu.front();
                qu.pop();
                int x = s.x, y = s.y, r = s.r;
                if(x == m - 1 && y == n - 1) {
                    return res;
                }
                for(int i = 0; i < 4; i++) {
                    int nx = x + dir[i][0], ny = y + dir[i][1];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n) {

                        if(grid[nx][ny] == 0 && !visited[nx][ny][r]) {
                            qu.emplace(nx, ny, r);
                            visited[nx][ny][r] = true;
                        }

                        if(grid[nx][ny] == 1 && r - 1 >= 0 && !visited[nx][ny][r-1]) {
                            qu.emplace(nx, ny, r-1);
                            visited[nx][ny][r-1] = true;
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
