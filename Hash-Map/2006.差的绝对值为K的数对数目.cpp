#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        map<int, int> mp;
        int res = 0;
        for(int& num : nums) {
            res += mp[num + k] + mp[num - k];
            mp[num]++;
        }
        return res;
    }
};
