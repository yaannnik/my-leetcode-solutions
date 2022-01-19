#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto& num : nums) {
            mp[num]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [&](pair<int, int>& p1, pair<int, int>& p2)
        {return p1.second != p2.second ? p1.second > p2.second : p1.first > p2.first;});
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.emplace_back(vec[i].first);
        }
        return res;
    }
};