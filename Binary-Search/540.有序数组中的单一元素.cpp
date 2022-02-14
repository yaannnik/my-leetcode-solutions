#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = 0;
        if(left == right) {
            return nums[left];
        }
        while(left <= right) {
            mid = left + (right - left) / 2;
            /*
             * 在单一元素之前，偶奇连等，之后奇偶连等，保证mid永远是偶数
             */
            if(mid % 2 == 1) {
                mid--;
            }
            if(nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};
