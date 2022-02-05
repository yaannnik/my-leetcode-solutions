#include <vector>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0, cnt = 0;
        for(auto& sides : rectangles) {
            if(min(sides[0], sides[1]) == maxLen) {
                cnt++;
            } else if(min(sides[0], sides[1]) > maxLen) {
                maxLen = min(sides[0], sides[1]);
                cnt = 1;
            }
        }
        return cnt;
    }
};
