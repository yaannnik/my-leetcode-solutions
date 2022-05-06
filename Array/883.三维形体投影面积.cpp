#include <vector>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    res++;
                }
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            int m = 0;
            for(int j = 0; j < grid[0].size(); j++) {
                m = max(m, grid[i][j]);
            }
            res += m;
        }
        for(int j = 0; j < grid[0].size(); j++) {
            int m = 0;
            for(int i = 0; i < grid.size(); i++) {
                m = max(m, grid[i][j]);
            }
            res += m;
        }
        return res;
    }
};
