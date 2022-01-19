#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int slow = 1, fast = 1;
        int res = 1, cnt = 1;

        while(slow < nums.size() && fast < nums.size()) {
            if(nums[fast] == nums[fast-1]) {
                cnt++;
                if(cnt > 2) {
                    fast++;
                    continue;
                }
            } else {
                cnt = 1;
            }
            nums[slow] = nums[fast];
            res++;
            slow++;
            fast++;
        }
        return res;
    }
};