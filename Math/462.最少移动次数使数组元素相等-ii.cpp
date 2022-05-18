#include <vector>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int& num : nums) {
            res += abs(num - nums[n/2]);
        }
        return res;
    }
};
