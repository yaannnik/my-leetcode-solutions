#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<char, int> smp, tmp;
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int st = -1, len = INT_MAX;
        for(int i = 0; i < t.size(); i++) {
            tmp[t[i]]++;
        }
        while(right < s.size()) {
            smp[s[right]]++;
            while(valid(smp, tmp) && left <= right) {
                if(right - left + 1 < len) {
                    st = left;
                    len = right- left + 1;
                }
                smp[s[left]]--;
                left++;
            }
            right++;
        }
        return st == -1 ? "" : s.substr(st, len);
    }

    bool valid(unordered_map<char, int>& smp, unordered_map<char, int>& tmp) {
        for(auto& p : tmp) {
            if(smp[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }
};
