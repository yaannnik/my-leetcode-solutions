#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            if(nums[i] > 0) {
                return res;
            }
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            helper(nums, i + 1, nums[i]);
        }
        return res;
    }

    void helper(vector<int>& nums, int l, int num) {
        int n = nums.size();
        int left = l, right = n - 1;

        while(left < right) {
            // left cannot be equal to right
            if(num + nums[left] + nums[right] == 0) {
                res.push_back({num, nums[left], nums[right]});
                while(left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while(left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if(num + nums[left] + nums[right] < 0) {
                while(left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                // 此处不能right--，否则若出现nums[left + 1] == nums[right]的情况会报错
                // while(left < right && nums[right] == nums[right - 1]) {
                //     right--;
                // }
                left++;
            } else {
                // 同理
                // while(left < right && nums[left] == nums[left + 1]) {
                //     left++;
                // }
                while(left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                right--;
            }

        }
    }

    vector<vector<int>> res;
};
