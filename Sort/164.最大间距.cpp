#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return 0;
        }

        int exp = 1;
        vector<int> buf(n);
        int max_val = *max_element(nums.begin(), nums.end());

        while(exp <= max_val) {
            vector<int> cnt(10, 0);
            for(int i = 0 ; i < n; i++) {
                int digit = (nums[i] / exp) % 10;
                cnt[digit]++;
            }
            for(int j = 1; j < 10; j++) {
                cnt[j] += cnt[j-1];
            }
            for(int k = n - 1; k >= 0; k--) {
                int digit = (nums[k] / exp) % 10;
                buf[cnt[digit]-1] = nums[k];
                cnt[digit]--;
            }
            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }

        int res = 0;
        for(int i = 1; i < n; i++) {
            res = max(res, nums[i] - nums[i-1]);
        }

        return res;
    }
};
