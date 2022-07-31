#include <vector>
using namespace std;

class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0, right = 0;
        int res = INT_MAX;
        for(; left < nums.size(); left++) {
            if(left > 0) {
                sum -= nums[left-1];
            }
            while(right < nums.size() && sum < target) {
                sum += nums[right];
                right++;
            }
            if(sum >= target) {
                res = min(res, right-left);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + nums[i];
        }
        int res = n + 1;
        for(int i = 0; i < n + 1; i++) {
            int left = i + 1, right = n;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                int subsum = pre[mid] - pre[i];
                if(subsum >= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if(left < n + 1 && pre[left] - pre[i] >= target) {
                res = min(res, left - i);
            }
        }
        return res <= n ? res : 0;
    }
};
