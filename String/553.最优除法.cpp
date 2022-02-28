#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return to_string(nums[0]);
        }
        if(n == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for(int i = 2; i < n; i++) {
            res += "/" + to_string(nums[i]);
        }
        res += ")";
        return res;
    }
};
