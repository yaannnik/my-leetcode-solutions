#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int res = majorityElementInRange(nums, left, right);
        return res;
    }

    int majorityElementInRange(vector<int>& nums, int left, int right) {
        if(left >= right) {
            return nums[right];
        }
        int mid = left + (right - left) / 2;
        int m1 = majorityElementInRange(nums, left, mid), m2 = majorityElementInRange(nums, mid + 1, right);
        if(m1 == m2) {
            return m1;
        }
        return countInRange(nums, left, right, m1) > countInRange(nums, left, right, m2) ? m1 : m2;
    }

    int countInRange(vector<int>& nums, int left, int right, int m) {
        int cnt = 0;
        for(int i = left; i <= right; i++) {
            if(nums[i] == m) {
                cnt++;
            }
        }
        return cnt;
    }

    int mooreVote(vector<int>& nums) {
        int candidate = nums[0], cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(cnt == 0) {
                candidate = nums[i];
                cnt = 1;
                continue;
            }
            if(nums[i] == candidate) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return candidate;
    }
};
