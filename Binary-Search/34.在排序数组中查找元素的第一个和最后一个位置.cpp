#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) {
            return {-1, -1};
        }
        int left = findLeft(nums, target), right = findRight(nums, target);
        return {left, right};
    }

    int findLeft(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] < target) {
                left = mid + 1;
            }
            //right会停留在target前的最后一个
            if(nums[mid] >= target) {
                right = mid - 1;
            }
        }
        return left < nums.size() && nums[left] == target ? left : -1;
    }

    int findRight(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while(left <= right) {
            int mid = left + (right-left)/2;
            //left会停留在target后的最前一个
            if(nums[mid] <= target) {
                left = mid + 1;
            }
            if(nums[mid] > target) {
                right = mid - 1;
            }
        }
        return right >= 0 && nums[right] == target ? right : -1;
    }
};
