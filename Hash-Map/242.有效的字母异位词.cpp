#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int sl = s.size(), tl = t.size();
        if(sl != tl) {
            return false;
        }
        unordered_map<char, int> mp;
        for(int i = 0; i < sl; i++) {
            if(mp.find(s[i]) == mp.end()) {
                mp.emplace(s[i], 1);
            } else {
                mp[s[i]]++;
            }
            if(mp.find(t[i]) == mp.end()) {
                mp.emplace(t[i], -1);
            } else {
                mp[t[i]]--;
            }
        }
        for(auto& p : mp) {
            if(p.second != 0) {
                return false;
            }
        }
        return true;
    }
};
