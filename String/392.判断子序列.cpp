#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int p1 = 0, p2 = 0;
        while(p1 < m && p2 < n) {
            if(s[p1] == t[p2]) {
                p1++;
                p2++;
            } else {
                p2++;
            }
        }
        return p1 == m;
    }
};
