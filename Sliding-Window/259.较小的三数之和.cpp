#include <vector>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size(), res = 0;
        if(n < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i + 2 < n; i++) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                if(nums[i] + nums[left] + nums[right] < target) {
                    res += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};
