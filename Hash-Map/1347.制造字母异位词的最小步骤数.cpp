#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        int diff = 0;
        unordered_map<char, int> mp;
        for(char& ch : s) {
            mp[ch]++;
        }
        for(char& ch : t) {
            mp[ch]--;
        }
        for(auto& [ch, cnt] : mp) {
            diff += abs(cnt);

        }
        return diff/2;
    }
};
