#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        stack<char> st;
        bool open = false;
        for(char& ch : s) {
            if(ch == '(') {
                open = true;
                st.push(ch);
            } else if(ch == ')') {
                if(open) {
                    int k = st.size();
                    int score = 1 << (k - 1);
                    res += score;
                    open = false;
                }
                st.pop();
            }
        }
        return res;
    }
};
