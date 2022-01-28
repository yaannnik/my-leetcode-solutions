#include <vector>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int res = oneLoop(nums);
        return res;
    }

    int oneLoop(vector<int>& nums) {
        int n = nums.size();
        int left_max = nums[0], global_max = nums[0];
        int idx = 0;
        for(int i = 0; i < n; i++) {
            global_max = max(global_max, nums[i]);
            // idx之前的数全部小于left_max
            if(nums[i] < left_max) {
                left_max = global_max;
                idx = i;
            }
        }
        return idx + 1;;
    }

    int twoLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmax(n, nums.front()), rightmin(n, nums.back());
        for(int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i-1], nums[i]);
            rightmin[n-1-i] = min(rightmin[n-i], nums[n-1-i]);
        }
        for(int i = 0; i < n - 1; i++) {
            if(leftmax[i] <= rightmin[i+1]) {
                return i + 1;
            }
        }
        return n;
    }
};
