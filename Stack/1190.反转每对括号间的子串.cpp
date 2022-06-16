#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                int start = st.top();
                st.pop();
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        string res = "";
        for(char& ch : s) {
            if(ch != '(' && ch != ')') {
                res += ch;
            }
        }
        return res;
    }
};
