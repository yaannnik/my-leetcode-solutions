#include <vector>
using namespace std;

/*
 * 先从后往前找第一个降序的数i，再从后往前找第一个大于i的数j
 * swap(i, j)
 * reverse i+1 -> end
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if(i >= 0) {
            int j = nums.size() - 1;
            while(j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
