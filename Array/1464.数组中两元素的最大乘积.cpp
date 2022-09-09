#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = (nums[n-1] - 1) * (nums[n-2] - 1);
        return res;
    }
};
