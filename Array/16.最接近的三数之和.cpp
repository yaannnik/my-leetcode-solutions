#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) {
            return 0;
        }
        if(n == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        int res = 0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // cout << sum << endl;
                if(sum < target) {
                    if(abs(sum - target) < diff) {
                        diff = abs(sum - target);
                        res = sum;
                    }
                    left++;
                } else if(sum > target) {
                    if(abs(sum - target) < diff) {
                        diff = abs(sum - target);
                        res = sum;
                    }
                    right--;
                } else {
                    return sum;
                }
            }

        }
        return res;
    }
};
