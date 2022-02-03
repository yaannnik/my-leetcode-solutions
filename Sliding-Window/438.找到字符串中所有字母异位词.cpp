#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), l = p.size();
        vector<int> res, smp(26, 0), lmp(26, 0);
        for(char& ch : p) {
            lmp[ch-'a']++;
        }
        int left = 0, right = 0;
        smp[s[right]-'a']++;
        while(right < n && left < n) {
            while(right - left + 1 < l && right + 1 < n) {
                right++;
                smp[s[right]-'a']++;
            }
            if(smp == lmp) {
                res.emplace_back(left);
            }
            left++;
            smp[s[left-1]-'a']--;
        }
        return res;
    }
};
