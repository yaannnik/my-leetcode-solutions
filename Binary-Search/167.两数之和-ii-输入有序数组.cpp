#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        for(int i = 0; i < n; i++) {
            int t = target - numbers[i];
            int idx = find(numbers, t, i + 1);
            if(idx >= 0) {
                res = {i + 1, idx + 1};
            }
        }
        return res;
    }

    int find(vector<int>& nums, int& target, int l) {
        int left = l, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};