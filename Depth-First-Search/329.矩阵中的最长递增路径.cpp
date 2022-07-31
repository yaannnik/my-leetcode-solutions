#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size(), cols = matrix[0].size();
        dist = vector<vector<int>>(rows, vector<int>(cols, 0));
        int res = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                res = max(res, dfs(i, j, matrix));
            }
        }
        return res;
    }

    int dfs(int x, int y, vector<vector<int>>& matrix) {
        if (dist[x][y] != 0) {
            return dist[x][y];
        }
        dist[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && matrix[nx][ny] > matrix[x][y]) {
                dist[x][y] = max(dist[x][y], dfs(nx, ny, matrix) + 1);
            }
        }
        return dist[x][y];
    }

    vector<vector<int>> dist;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int rows, cols;
};
