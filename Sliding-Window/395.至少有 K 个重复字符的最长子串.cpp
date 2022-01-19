#include <vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k <= 1) {
            return s.size();
        }
        if(s.empty() || s.size() < k) {
            return 0;
        }
        vector<int> hash(26, 0);
        for(char& c : s) {
            hash[c-'a']++;
        }
        int i = 0;
        while(i < s.size() && hash[s[i]-'a'] >= k) {
            i++;
        }
        if(i == s.size()) {
            return s.size();
        }
        int l = longestSubstring(s.substr(0, i), k);

        while(i < s.size() && hash[s[i]-'a'] < k) {
            i++;
        }
        int r = longestSubstring(s.substr(i), k);

        return max(l, r);
    }
};
