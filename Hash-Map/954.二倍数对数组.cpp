#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<double, int> mp;
        for (auto& num : arr) {
            mp[num]++;
        }
        for (auto& [num, cnt] : mp) {
            if (cnt < 0) return false;
            if (cnt == 0) continue;
            if (num > 0) {
                if (!mp.count(num * 2)) return false;
                mp[num * 2] -= cnt;
            } else {
                if (!mp.count(num / 2.0)) return false;
                mp[num / 2.0] -= cnt;
            }
        }
        return true;
    }
};
