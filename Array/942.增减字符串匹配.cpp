#include <vector>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size() + 1;
        vector<int> nums(n), res;
        iota(nums.begin(), nums.end(), 0);
        int i = 0, d = n - 1;
        for(char& ch : s) {
            if(ch == 'I') {
                res.emplace_back(nums[i]);
                i++;
            } else {
                res.emplace_back(nums[d]);
                d--;
            }
        }
        res.emplace_back(nums[i]);
        return res;
    }
};
