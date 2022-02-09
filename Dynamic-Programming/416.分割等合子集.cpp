#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;
        if(*max_element(nums.begin(), nums.end()) > target) {
            return false;
        }

        /**
         * dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），
         * 是否存在一种选取方案使得被选取的正整数的和等于 j。初始时，dp 中的全部元素都是 false。
         */
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        dp[0][nums[0]] = true;
        for(int i = 0; i < n; i++) {
            dp[i][0] = true; // 选中0个数字
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                if(j >= nums[i]) {
                    dp[i][j] = dp[i-1][j-nums[i]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
};
