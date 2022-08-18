#include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int upperBound = findUpperBound(nums, j + 1, nums[i] + nums[j]);
                // 不需要考虑两边之差小于第三边的情况
                // int lowerBound = findLowerBound(nums, j + 1, abs(nums[i] - nums[j]));

                res += max(0, upperBound - j);
            }
        }
        return res;
    }

    int findUpperBound(vector<int>& nums, int left, int target) {
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }

    int findLowerBound(vector<int>& nums, int left, int target) {
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
