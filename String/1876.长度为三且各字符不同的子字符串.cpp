#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3) {
            return 0;
        }
        int res = 0;
        for(int i = 0; i < s.size() - 2; i++) {
            if(good(s.substr(i, 3))) {
                res++;
            }
        }
        return res;
    }

    bool good(string s) {
        set<char> st(s.begin(), s.end());

        return st.size() == 3;
    }
};
