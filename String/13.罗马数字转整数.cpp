#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int i = 0, n = s.size();
        int res = 0;
        while(i < n) {
            if(i + 1 < n && mp[s[i+1]] > mp[s[i]]) {
                res += mp[s[i+1]] - mp[s[i]];
                i += 2;
            } else {
                res += mp[s[i]];
                i++;
            }
        }
        return res;
    }
};