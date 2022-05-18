#include <string>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.size(), n = second.size();
        if(abs(m - n) >= 2) {
            return false;
        }
        if(m == n) {
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                if(first[i] != second[i]) {
                    cnt++;
                }
            }
            return cnt <= 1;
        } else {
            string l, s;
            if(m >= n) {
                l = first, s = second;
            } else {
                l = second, s = first;
            }

            int pl = 0, ps = 0;
            int cnt = 0;

            while(pl < l.size() && ps < s.size()) {
                if(l[pl] != s[ps]) {
                    if(cnt < 1) {
                        pl++;
                        cnt++;
                    } else {
                        return false;
                    }
                } else {
                    pl++;
                    ps++;
                }
            }
        }
        return true;
    }
};
