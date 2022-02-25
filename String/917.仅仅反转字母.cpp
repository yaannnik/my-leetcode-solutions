#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            while(l < s.size() && !((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z'))) {
                l++;
            }
            while(r >= 0 && !((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z'))) {
                r--;
            }
            if(l < r && l < s.size() && r >= 0) {
                swap(s[l], s[r]);
            }
            l++;
            r--;
        }
        return s;
    }
};
