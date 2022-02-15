#include <vector>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        // 对是'D'的部分倒序排列
        int n = s.size() + 1;
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == 'I') {
                continue;
            }
            int start = i;
            while(s[i] == 'D' && i < n - 1) {
                i++;
            }
            reverse(nums.begin() + start, nums.begin() + i + 1);
            i--;
        }
        return nums;
    }
};
