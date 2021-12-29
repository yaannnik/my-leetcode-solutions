#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int res = 1;
        int fast = 1, slow = 1;
        while(fast < nums.size() && slow < nums.size()) {
            if(nums[fast] == nums[fast-1]) {
                fast++;
                continue;
            }
            nums[slow] = nums[fast];
            res++;
            slow++;
            fast++;
        }
        return res;
    }
};

