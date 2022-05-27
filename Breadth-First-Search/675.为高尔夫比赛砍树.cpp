#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> trees;
        int row = forest.size();
        int col = forest[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(i, j);
                }
            }
        }
        sort(trees.begin(), trees.end(), [&](const pair<int, int> & a, const pair<int, int> & b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });

        int cx = 0;
        int cy = 0;
        int ans = 0;
        for (int i = 0; i < trees.size(); ++i) {
            int steps = bfs(forest, cx, cy, trees[i].first, trees[i].second);
            if (steps == -1) {
                return -1;
            }
            ans += steps;
            cx = trees[i].first;
            cy = trees[i].second;
        }
        return ans;
    }

    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        if(sx == tx && sy == ty) {
            return 0;
        }
        int m = forest.size(), n = forest[0].size();
        int step = 0;

        queue<pair<int, int>> qu;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        qu.emplace(sx, sy);
        visited[sx][sy] = true;

        while(!qu.empty()) {
            int k = qu.size();
            for(int i = 0; i < k; i++) {
                auto [x, y] = qu.front();
                qu.pop();
                for(auto& d : dir) {
                    int dx = d[0] + x, dy = d[1] + y;
                    if(dx >= 0 && dx < m && dy >= 0 && dy < n) {
                        if(!visited[dx][dy] && forest[dx][dy] > 0) {
                            if(dx == tx && dy == ty) {
                                return step + 1;
                            }
                            qu.emplace(dx, dy);
                            visited[dx][dy] = true;
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
