#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int,int> mp;
        mp.insert({0, 1});
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            //计算之前有多少个前缀和为sum-k的组合，总结果就增加mp[sum-k]
            if(mp.find(sum-k) != mp.end()) {
                res += mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};
