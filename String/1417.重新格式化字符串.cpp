#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> digits, chars;
        for(char& ch : s) {
            if(ch >= '0' && ch <= '9') {
                digits.emplace_back(ch);
            } else {
                chars.emplace_back(ch);
            }
        }
        int lenDigits = digits.size(), lenChars = chars.size();
        // cout << lenChars << " " << lenDigits << " " << abs(lenChars - lenChars) << endl;
        if(abs(lenChars - lenDigits) > 1) {
            return "";
        }

        string res(lenDigits + lenChars, ' ');
        if(lenChars > lenDigits) {
            int p = 0;
            for(int i = 0; i < lenChars; i++) {
                res[p] = chars[i];
                p += 2;
            }
            p = 1;
            for(int i = 0; i < lenDigits; i++) {
                res[p] = digits[i];
                p += 2;
            }
        } else {
            int p = 0;
            for(int i = 0; i < lenDigits; i++) {
                res[p] = digits[i];
                p += 2;
            }
            p = 1;
            for(int i = 0; i < lenChars; i++) {
                res[p] = chars[i];
                p += 2;
            }
        }
        return res;
    }
};
