#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), m = 0;
        for(int i = 0; i < n; i++) {
            if(i <= m) {
                m = max(m, i + nums[i]);
            }
        }
        return m >= n - 1;
    }
};
