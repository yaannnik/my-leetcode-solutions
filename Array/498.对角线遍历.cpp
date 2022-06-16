#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        int x = 0, y = 0;
        int direct = 0; // 0 for right up, 1 for left down
        vector<vector<int>> d = {{-1, 1}, {1, -1}};
        while(res.size() < m * n) {
            // cout << "(" << x << ", " << y << ")" << endl;
            res.emplace_back(mat[x][y]);
            if(direct == 0 && (x == 0 || y == n - 1)) {
                direct = 1;
                if(y == n - 1) { // 如果同时满足，优先考虑这种
                    x += 1;
                } else if(x == 0) {
                    y += 1;
                }
                continue;
            }
            if(direct == 1 && (y == 0 || x == m - 1)) {
                direct = 0;
                if(x == m - 1) { //如果同时满足，优先考虑这种
                    y += 1;
                } else if(y == 0) {
                    x += 1;
                }
                continue;
            }
            x += d[direct][0];
            y += d[direct][1];
        }
        return res;
    }
};
