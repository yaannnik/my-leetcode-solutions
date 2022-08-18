#include <vector>
using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());
        int mostLeftMin = 0, mostRightMax = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == minElement) {
                mostLeftMin = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] == maxElement) {
                mostRightMax = i;
                break;
            }
        }
        if(mostLeftMin < mostRightMax) {
            return mostLeftMin + (n - 1) - mostRightMax;
        } else {
            return mostLeftMin + (n - 1) - mostRightMax - 1;
        }
    }
};
