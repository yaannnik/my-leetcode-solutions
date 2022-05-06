#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0] == 0) return "0";
        string res;
        for(auto& num : nums) {
            res += to_string(num);
        }
        return res;
    }

    bool static cmp(int x, int y) {
        long sx = 10, sy = 10;
        while(sx <= x) {
            sx *= 10;
        }
        while(sy <= y) {
            sy *= 10;
        }
        return (sy * x + y) > (sx * y + x);
    }
};
