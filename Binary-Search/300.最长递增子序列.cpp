#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int& num : nums) {
            if(res.empty() || num > res.back()) {
                res.emplace_back(num);
            } else {
                int left = 0, right = res.size() - 1;
                while(left <= right) {
                    int mid = left + (right - left) / 2;
                    if(res[mid] >= num) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                res[right+1] = num;
            }
        }
        return res.size();
    }
};
