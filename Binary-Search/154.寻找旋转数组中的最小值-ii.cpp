#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(mid > 0 && nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if(nums[mid] < nums[right]) {
                right = mid - 1;
            }
            else {
                right--;
            }
        }
        return nums[left];
    }
};
