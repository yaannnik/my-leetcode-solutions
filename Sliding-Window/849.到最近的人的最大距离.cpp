#include <vector>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left = -1, right = 0;
        int dist = 0;
        /**
         * 处理三种情况：
         * 坐在最左边
         * 坐在最右边
         * 坐在两个人中间
         */
        while(right < seats.size()) {
            if(seats[right] == 0) {
                right++;
                continue;
            }
            if(left == -1) {
                //坐在最左边
                dist = right - left - 1;
            } else {
                //坐在两个人中间
                if((right-left)/2 > dist) {
                    dist = (right-left)/2;
                }
            }
            left = right;
            right++;
        }
        //坐在最右边
        if(right - left - 1 > dist) {
            dist = right - left - 1;
        }
        return dist;
    }
};
