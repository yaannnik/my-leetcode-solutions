#include <string>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        if(s1.size() != s2.size()) {
            return false;
        }
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) {
                cnt++;
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return cnt <= 2 && s1 == s2;
    }
};
