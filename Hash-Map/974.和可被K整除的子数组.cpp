#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> subsum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            subsum[i + 1] = nums[i] + subsum[i];
        }
        unordered_map<int, int> mod2num;
        mod2num[0] = 1; // nums[0:i]可整除
        int res = 0;

        for(int i = 1; i <= n; i++) {
            int mod = subsum[i] % k;
            // 处理前缀和为负数的情况
            if(mod < 0) {
                mod += k;
            }
            res += mod2num[mod];
            mod2num[mod]++;
        }

        return res;
    }
};
