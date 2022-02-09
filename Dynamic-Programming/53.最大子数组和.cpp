#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], tmp = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            // 如果 nums[i] + 前缀和 还不如当前nums[i]大，直接丢弃前缀和
            tmp = max(tmp + nums[i], nums[i]);
            res = max(res, tmp);
        }
        return res;
    }
};
