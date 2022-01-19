#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        idx[nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(idx.find(target-nums[i]) != idx.end()) {
                return {idx[target-nums[i]], i};
            } else {
                idx[nums[i]] = i;
            }
        }
        return {0, 0};
    }
};
