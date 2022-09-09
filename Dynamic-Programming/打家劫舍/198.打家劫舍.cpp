#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        dp[2] = nums[1];
        for(int i = 2; i < n; i++) {
            dp[i + 1] = max(dp[i-1], dp[i-2]) + nums[i];
        }
        return max(dp[n], dp[n-1]);
    }
};

class Solution2 {
public:
    int rob(vector<int>& nums) {
        int sumEven = 0;
        int sumOdd = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i%2 == 0){
                sumEven += nums[i];
                sumEven = max(sumEven, sumOdd);
            }
            else{
                sumOdd += nums[i];
                sumOdd = max(sumEven, sumOdd);
            }
        }
        return max(sumEven, sumOdd);
    }
};
