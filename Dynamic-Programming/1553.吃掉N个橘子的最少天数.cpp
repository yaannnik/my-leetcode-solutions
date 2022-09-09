#include <unordered_map>
using namespace std;

class Solution {
public:
    int minDays(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }
        if(mp.count(n)) {
            return mp[n];
        }
        mp[n] = min(minDays(n / 2) + n % 2, minDays(n / 3) + n % 3) + 1;
        // 这一天是吃掉1/2或者2/3的一天
        return mp[n];
    }

    unordered_map<int, int> mp;
};
