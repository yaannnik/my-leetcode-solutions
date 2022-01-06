#include<vector>
using namespace std;

class Solution {
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
