#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = y, right = y, up = x, down = x;
        queue<pair<int,int>> qu;
        qu.push(pair<int,int>(x, y));
        image[x][y] = '2';
        while(!qu.empty()) {
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                auto front = qu.front();
                qu.pop();
                int x_ = front.first, y_ = front.second;
                up = min(up, x_);
                down = max(down, x_);
                left = min(left, y_);
                right = max(right, y_);
                //up
                if(x_ - 1 >= 0 && image[x_ - 1][y_] == '1') {
                    image[x_ - 1][y_] = '2';
                    qu.push(pair<int,int>(x_ - 1, y_));
                }
                //down
                if(x_ + 1 <= image.size()-1 && image[x_ + 1][y_] == '1') {
                    image[x_ + 1][y_] = '2';
                    qu.push(pair<int,int>(x_ + 1, y_));
                }
                //left
                if(y_ - 1 >= 0 && image[x_][y_ - 1] == '1') {
                    image[x_][y_ - 1] = '2';
                    qu.push(pair<int,int>(x_, y_ - 1));
                }
                //right
                if(y_ + 1 <= image[0].size()-1 && image[x_][y_ + 1] == '1') {
                    image[x_][y_ + 1] = '2';
                    qu.push(pair<int,int>(x_, y_ + 1));
                }
            }
        }
        return (right-left+1)*(down-up+1);
    }
};
