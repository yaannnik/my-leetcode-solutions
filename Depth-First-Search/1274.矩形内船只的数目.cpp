#include <vector>
using namespace std;

// This is Sea's API interface.
// You should not implement it, or speculate about its implementation
class Sea {
  public:
    bool hasShips(vector<int> topRight, vector<int> bottomLeft);
};


class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int bottomLeft_x = bottomLeft[0], bottomLeft_y = bottomLeft[1];
        int topRight_x = topRight[0], topRight_y = topRight[1];

        if(bottomLeft_x == topRight_x && bottomLeft_y == topRight_y) {
            if(sea.hasShips(topRight, bottomLeft)) {
                return 1;
            } else {
                return 0;
            }
        }

        int mid_x = bottomLeft_x + (topRight_x - bottomLeft_x) / 2;
        int mid_y = bottomLeft_y + (topRight_y - bottomLeft_y) / 2;
        int res = 0;

        if(mid_x >= bottomLeft[0] && mid_y >= bottomLeft[1] && sea.hasShips({mid_x, mid_y}, bottomLeft)) {
            // 左下
            res += countShips(sea, {mid_x, mid_y}, bottomLeft);
        }
        if(topRight_x >= mid_x + 1 && mid_y >= bottomLeft_y && sea.hasShips({topRight_x, mid_y}, {mid_x + 1, bottomLeft_y})) {
            // 右下
            res += countShips(sea, {topRight_x, mid_y}, {mid_x + 1, bottomLeft_y});
        }
        if(mid_x >= bottomLeft_x && topRight_y >= mid_y + 1 && sea.hasShips({mid_x, topRight_y}, {bottomLeft_x, mid_y + 1})) {
            // 左上
            res += countShips(sea, {mid_x, topRight_y}, {bottomLeft_x, mid_y + 1});
        }
        if(topRight[0] >= mid_x + 1 && topRight[1] >= mid_y + 1 && sea.hasShips(topRight, {mid_x + 1, mid_y + 1})) {
            // 右上
            res += countShips(sea, topRight, {mid_x + 1, mid_y + 1});
        }

        return res;
    }
};
