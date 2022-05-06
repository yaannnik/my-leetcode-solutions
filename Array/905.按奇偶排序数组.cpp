#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            while(l < r && nums[l] % 2 == 0) {
                l++;
            }
            while(l < r && nums[r] % 2 == 1) {
                r--;
            }
            swap(nums[l], nums[r]);
        }
        return nums;
    }
};
