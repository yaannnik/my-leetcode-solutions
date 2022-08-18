#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        stack<char> stk;
        for(char& ch : s) {
            if(ch == '(') {
                stk.push(ch);
                res = max((int)stk.size(), res);
            } else if(ch == ')') {
                stk.pop();
            }
        }
        return res;
    }
};
