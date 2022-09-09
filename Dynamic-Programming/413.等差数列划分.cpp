#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() <= 2) {
            return 0;
        }
        int res = 0;
        int len = 0;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                len++;
                res += len;
            } else {
                len = 0;
            }
        }
        return res;
    }
};
