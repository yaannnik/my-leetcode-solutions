#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // (n - 1) * x + sum = n * (min + x)
        int n = nums.size();
        int m = *min_element(nums.begin(), nums.end());
        int s = accumulate(nums.begin(), nums.end(), 0);
        return s - n * m;
    }
};
