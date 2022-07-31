#include <vector>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int max_ = INT_MIN, min_ = INT_MAX;
        for(auto& num : nums) {
            max_ = max(num, max_);
            min_ = min(num, min_);
        }
        return max(0, max_ - min_ - 2 * k);
    }
};
