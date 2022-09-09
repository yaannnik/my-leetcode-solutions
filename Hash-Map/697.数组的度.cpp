#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp, left, right;
        int degree = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            mp[num]++;
            degree = max(degree, mp[num]);
            if(!left.count(num)) {
                left[num] = i;
            }
            right[num] = i;
        }
        int res = nums.size();
        for(auto [num, deg] : mp) {
            if(deg == degree) {
                res = min(res, right[num] - left[num] + 1);
            }
        }
        return res;
    }
};
