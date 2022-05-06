#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if(arr.empty()) {
            return 0;
        }
        unordered_map<int, int> mp_tmp;
        for(auto& i : arr) {
            if(mp_tmp.find(i) == mp_tmp.end()) {
                mp_tmp.insert(pair<int, int>(i, 1));
            } else {
                mp_tmp[i]++;
            }
        }
        vector<pair<int, int>> mp;
        for(auto& p : mp_tmp) {
            mp.emplace_back(p);
        }
        sort(mp.begin(), mp.end(), [=](pair<int, int>& a, pair<int, int>& b) {return a.second < b.second;});
        for(int i = 0; i < mp.size(); i++) {
            int num = mp[i].second;
            if(k - num >= 0) {
                k -= num;
                continue;
            } else {
                return mp.size() - i;
            }
        }
        return 0;
    }
};
