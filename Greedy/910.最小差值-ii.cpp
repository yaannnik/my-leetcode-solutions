#include <vector>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums.front();
        for(int i = 0; i < nums.size() - 1; i++) {
            // [0:i] + k, [i+1:] - k
            int a = nums[i], b = nums[i+1];
            int low = min(nums.front() + k, b - k);
            int high = max(nums.back() - k, a + k);
            res = min(res, high - low);
        }
        return res;
    }
};
