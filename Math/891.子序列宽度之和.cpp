#include <vector>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long> pow2(n, 0);
        pow2[0] = 1;
        for(int i = 1; i < n; ++i)
            pow2[i] = pow2[i-1] * 2 % MOD;

        long ans = 0;
        for(int i = 0; i < n; ++i)
            ans = (ans + (pow2[i] - pow2[n-1-i]) * nums[i]) % MOD;

        return (int)ans;
    }
};
