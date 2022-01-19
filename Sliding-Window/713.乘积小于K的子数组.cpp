#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0 || k == 1) {
            return 0;
        }
        int mul = 1, res = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++) {
            mul *= nums[r];
            while(mul >= k) {
                mul /= nums[l];
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }
};
