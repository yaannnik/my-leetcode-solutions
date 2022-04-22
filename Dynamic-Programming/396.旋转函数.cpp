#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // F(i) = F(i-1) - sum(nums) + n * nums[i-1];
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> F(n, 0);
        for(int i = 0; i < n; i++) {
            F[0] += i * nums[i];
        }
        int res = F[0];
        for(int i = 1; i < n; i++) {
            F[i] = F[i-1] - sum + n * nums[i-1];
            res = max(res, F[i]);
        }
        return res;
    }
};
