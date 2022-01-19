#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        sort(nums2.begin(), nums2.end());

        for(auto& num : nums1) {
            mp[num]++;
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(i > 0 && nums2[i] == nums2[i-1]) {
                continue;
            }
            if(mp.find(nums2[i]) != mp.end()) {
                res.emplace_back(nums2[i]);
            }
        }

        return res;
    }
};
