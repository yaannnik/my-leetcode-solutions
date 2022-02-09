#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        vector<int> cnt(n, 0);
        for(int& num : nums) {
            cnt[num]++;
        }
        return min_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};
