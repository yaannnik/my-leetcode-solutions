#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = i + 1;
        while(i < nums.size() && j < nums.size()) {
            if(nums[i] == 0) {
                if(nums[j] != 0) {
                    swap(nums[i++], nums[j++]);
                } else {
                    j++;
                }
            } else {
                i++;
                j = i + 1;
            }
        }
    }
};