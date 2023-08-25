#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<int> qu;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    qu.emplace(i * m + j);
                    isWater[i][j] = -1;
                }
            }
        }
        while(!qu.empty()) {
            int top = qu.front();
            qu.pop();
            int x = top / m, y = top % m;
            if(x - 1 >= 0 && isWater[x - 1][y] != -1) {
                res[x - 1][y] = res[x][y] + 1;
                qu.emplace((x - 1) * m + y);
                isWater[x - 1][y] = -1;
            }
            if(x + 1 < m && isWater[x + 1][y] != -1) {
                res[x + 1][y] = res[x][y] + 1;
                qu.emplace((x + 1) * m + y);
                isWater[x + 1][y] = -1;
            }
            if(y - 1 >= 0 && isWater[x][y - 1] != -1) {
                res[x][y - 1] = res[x][y] + 1;
                qu.emplace(x * m + y - 1);
                isWater[x][y - 1] = -1;
            }
            if(y + 1 < n && isWater[x][y + 1] != -1) {
                res[x][y + 1] = res[x][y] + 1;
                qu.emplace(x * m + y + 1);
                isWater[x][y + 1] = -1;
            }
        }
        return res;
    }
};
