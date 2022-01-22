#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < time.size(); i++) {
            int r = time[i] % 60; 
            if(mp.find((60 - r) % 60) != mp.end()) {
                res += mp[(60 - r) % 60];
            }

            if(mp.find(r) == mp.end()) {
                mp.emplace(r, 1);
            } else {
                mp[r]++;
            }
        }
        return res;
    }
};
// @lc code=end

