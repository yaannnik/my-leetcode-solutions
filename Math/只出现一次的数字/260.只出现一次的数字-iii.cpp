#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long tmp = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            tmp = tmp ^ nums[i];
        }
        // 找出最低位的1
        long mask = tmp & (-tmp);
        int res1 = 0;
        for(int& num : nums) {
            if(num & mask) {
                res1 ^= num;
            }
        }
        int res2 = res1 ^ tmp;
        return {res1, res2};
    }
};
