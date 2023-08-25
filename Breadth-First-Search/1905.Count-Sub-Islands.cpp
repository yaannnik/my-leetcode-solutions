#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(grid1.empty() || grid1[0].empty()) {
            return 0;
        }
        
        int count = 0;
        int rows = grid1.size(), cols = grid1[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid2[i][j] == 1) {
                    // cout << i << " " << j << endl;
                    count += checkSubIsland(grid1, grid2, i, j);
                }
            }
        }
                
        return count;
    }
    
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y) {
        bool valid = true;
        int rows = grid1.size(), cols = grid1[0].size();
        
        queue<pair<int, int>> qu;
        qu.emplace(x, y);
        grid2[x][y] = -1;
        if(grid1[x][y] != 1) {
            valid = false;
        }
        
        while(!qu.empty()) {
            auto [xx, yy] = qu.front();
            // cout << xx << " " << yy << " " << grid2[xx][yy] << endl;
            qu.pop();
            for(int i = 0; i < 4; i++) {
                int nx = xx + dir[i][0], ny = yy + dir[i][1];
                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid2[nx][ny] == 1) {
                    if(grid1[nx][ny] != 1) {
                        valid = false;
                    }
                    qu.emplace(nx, ny);
                    grid2[nx][ny] = -1;
                    // cout << grid2[nx][ny] << endl;
                }
            }
        }
        
        return valid;
    }
    
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};