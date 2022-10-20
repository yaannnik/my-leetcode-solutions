#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1) {
            if(n > 1) {
                return s;
            }
        }
        vector<string> rowString(numRows);
        int r = 0;
        int dir = 0; // 0 for down and 1 for up
        for(int i = 0; i < n; i++) {
            rowString[r] += s[i];
            if(dir == 0) {
                if(r == numRows - 1) {
                    r--;
                    dir = 1;
                } else {
                    r++;
                }
            } else {
                if(r == 0) {
                    r++;
                    dir = 0;
                } else {
                    r--;
                }
            }
        }
        string res = "";
        for(string& str : rowString) {
            res += str;
        }
        return res;
    }
};
