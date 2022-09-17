#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int& num : arr) {
            mp[num]++;
        }

        vector<pair<int, int>> vmp;
        for(auto p : mp) {
            vmp.push_back(p);
        }

        sort(vmp.begin(), vmp.end(), [&](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        });
        int cnt = 0;
        int i = 0, res = 0;
        while(cnt < n / 2) {
            cnt += vmp[i].second;
            res++;
            i++;
        }
        return res;
    }
};
