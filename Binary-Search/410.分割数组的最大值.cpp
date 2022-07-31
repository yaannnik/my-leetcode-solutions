#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(nums, mid, m)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(vector<int>& nums, int k, int m) {
        int cuts = 1;
        int tmp = 0;
        for(int& num : nums) {
            if(tmp + num > k) {
                cuts++;
                tmp = num;
            } else {
                tmp += num;
            }
        }
        return cuts <= m;
    }
};
