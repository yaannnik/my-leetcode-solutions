#include <vector>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int pre = nums[0], res = 0;
        for(vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++) {
            if(*it > pre) {
                res = max(*it - pre, res);
            }
            pre = min(pre, *it);
        }
        return res == 0 ? -1 : res;
    }
};
