#include <vector>
#include <utility>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        if(x == 0 && y == 0) {
            return 0;
        }
        vector<vector<int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        queue<pair<int, int>> qu;
        set<pair<int, int>> visited;
        qu.emplace(0, 0);
        int res = 0;
        while(!qu.empty()) {
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                auto [x_, y_] = qu.front();
                qu.pop();
                if(x_ == abs(x) && y_ == abs(y)) {
                    return res;
                }
                for(int j = 0; j < 8; j++) {
                    int nx = x_ + dir[j][0], ny = y_ + dir[j][1];
                    if(nx >= -2 && nx <= abs(x) + 2 && ny >= -2 && ny <= abs(y) + 2 && !visited.count({nx, ny})) {
                        qu.emplace(x_ + dir[j][0], y_ + dir[j][1]);
                        visited.insert({x_ + dir[j][0], y_ + dir[j][1]});
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
