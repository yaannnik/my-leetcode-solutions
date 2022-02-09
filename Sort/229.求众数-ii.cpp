#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = nums[0], candidate2 = nums[0];
        int cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        for(int& num : nums) {
            if(num == candidate1) {
                cnt1++;
            } else if(num == candidate2) {
                cnt2++;
            } else if(cnt1 == 0) {
                candidate1 = num;
                cnt1++;
            } else if(cnt2 == 0) {
                candidate2 = num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int& num : nums) {
            if(num == candidate1) {
                cnt1++;
            }
            if(num == candidate2) {
                cnt2++;
            }
        }
        vector<int> res;
        if(cnt1 > n / 3) {
            res.emplace_back(candidate1);
        }
        if(cnt2 > n / 3 && candidate2 != candidate1) {
            res.emplace_back(candidate2);
        }
        return res;
    }
};
