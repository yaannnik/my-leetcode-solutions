#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size(), cols = image[0].size();
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> qu;
        if(image[sr][sc] != color) {
            qu.emplace(sr, sc);
        }

        int start = image[sr][sc];
        while(!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();
            // cout << x << " " << y << endl;
            image[x][y] = color;
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && image[nx][ny] == start) {
                    qu.emplace(nx, ny);
                }
            }
        }

        return image;
    }
};
