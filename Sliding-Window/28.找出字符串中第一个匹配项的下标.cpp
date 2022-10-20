#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(m < n) {
            return -1;
        }
        if(haystack == needle || haystack.substr(0, n) == needle) {
            return 0;
        }
        string win = haystack.substr(0, n);
        for(int i = n; i < m; i++) {
            win.erase(win.begin());
            win += haystack[i];
            if(win == needle) {
                return i - n + 1;
            }
        }
        return -1;
    }
};
