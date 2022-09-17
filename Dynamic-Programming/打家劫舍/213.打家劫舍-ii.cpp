#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        return max(robrange(nums, 0, n - 2), robrange(nums, 1, n - 1));
    }

    int robrange(vector<int>& nums, int start, int end) {
        int even = 0, odd = 0;
        for(int i = start; i <= end; i++) {
            if(i % 2 == 0) {
                even += nums[i];
                even = max(even, odd);
            } else {
                odd += nums[i];
                odd = max(odd, even);
            }
        }
        return max(odd, even);
    }
};
