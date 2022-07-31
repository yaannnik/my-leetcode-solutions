#include <vector>
using namespace std;

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int p1 = 0, p2 = slow;
        while(p1 != p2) {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return p1;
    }
};

class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++) {
                cnt += (nums[i] <= mid);
            }
            if(cnt <= mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // 找到第一个不满足cnt <= i的数
        return left;
    }
};
