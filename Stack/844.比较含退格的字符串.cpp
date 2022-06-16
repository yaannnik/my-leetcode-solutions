#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, tt;
        for(char& ch : s) {
            if(ch == '#') {
                if(!ss.empty()) {
                    ss.pop();
                }
            } else {
                ss.push(ch);
            }
        }

        for(char& ch : t) {
            if(ch == '#') {
                if(!tt.empty()) {
                    tt.pop();
                }
            } else {
                tt.push(ch);
            }
        }

        while(!ss.empty() && !tt.empty()) {
            char stop = ss.top();
            ss.pop();
            char ttop = tt.top();
            tt.pop();
            if(stop != ttop) {
                return false;
            }
        }

        return ss.empty() && tt.empty();
    }
};
