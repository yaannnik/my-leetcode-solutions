#include <vector>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX, n = nums.size();
        for(int i = 0; i + (k - 1) < n; i++) {
            res = min(nums[i + (k - 1)] - nums[i], res);
        }
        return res;
    }
};
