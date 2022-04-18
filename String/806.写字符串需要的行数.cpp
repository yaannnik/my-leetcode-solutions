#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int len = 0;
        for(char& ch : s) {
            if(len + widths[ch-'a'] <= 100) {
                len += widths[ch-'a'];
            } else {
                len = widths[ch-'a'];
                lines++;
            }
        }
        return {lines, len};
    }
};
