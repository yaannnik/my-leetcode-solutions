#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        vector<int> tmp = nums;
        int k = 0, n = tmp.size();
        int pivot = (n + 1) / 2;
        for(int i = pivot - 1; i >= 0; i--) {
            nums[k] = tmp[i];
            k += 2;
        }
        k = 1;
        for(int i = n - 1; i >= pivot; i--) {
            nums[k] = tmp[i];
            k += 2;
        }
    }
};
