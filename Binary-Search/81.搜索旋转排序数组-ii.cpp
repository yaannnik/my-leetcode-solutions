#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[mid] < nums[right]) {
                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            else if(nums[mid] > nums[right]) {
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                right--;
            }
        }
        return false;
    }
};
