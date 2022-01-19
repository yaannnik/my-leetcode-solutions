#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0, right = 0;
        int res = INT_MAX;
        for(; left < nums.size(); left++) {
            if(left > 0) {
                sum -= nums[left-1];
            }
            while(right < nums.size() && sum < target) {
                sum += nums[right];
                right++;
            }
            if(sum >= target) {
                res = min(res, right-left);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
