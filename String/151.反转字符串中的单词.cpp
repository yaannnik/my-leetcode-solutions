#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int w = 0;
        for(int i = 0; i < n; i++) {
            if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9') ) {

                if(i > 0 && s[i-1] == ' ') {
                    if(w != 0) {
                        s[w] = ' ';
                        w++;
                    }
                }
                s[w] = s[i];
                // cout << s[i] << endl;
                w++;
            }

        }
        s = s.substr(0, w);
        reverseString(s);
        return s;
    }

    void reverseString(string& s) {
        int n = s.size();
        int left = 0, right = -1;
        for(int i = 0; i < n; i++) {
            if(i == 0 || s[i-1] == ' ') {
                // cout << "left" << endl;
                left = i;
                continue;
            }
            if(i == n - 1 || s[i+1] == ' ') {
                right = i;
                // cout << "right" << endl;
                reverse(s.begin() + left, s.begin() + right + 1);
                continue;
            }
        }
        reverse(s.begin(), s.end());
    }
};
