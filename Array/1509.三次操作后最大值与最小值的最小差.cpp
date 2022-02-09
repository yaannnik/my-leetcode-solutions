#include <vector>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        /**
         * The minimum difference possible is is obtained by removing 3 elements
         * between the 3 smallest and 3 largest values in the array.
         */
        int n = nums.size(), res = INT_MAX;
        sort(nums.begin(), nums.end());
        if(n <= 3) {
            return 0;
        }
        for(int i = 0; i <= 3; i++) {
            // remove i from the first three and (3-i) from the last three
            res = min(res, nums[n-1-(3-i)]-nums[i]);
        }
        return res;
    }
};
