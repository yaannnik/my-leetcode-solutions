#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(auto& num1 : nums1) {
            mp[num1]++;
        }
        for(auto& num2 : nums2) {
            if(mp.find(num2) != mp.end() && mp[num2] > 0) {
                res.emplace_back(num2);
                mp[num2]--;
            }
        }
        return res;
    }
};
