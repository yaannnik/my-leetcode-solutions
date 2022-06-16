#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char& ch : s) {
            if(!st.empty() && st.top() == ch) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        string res = "";
        while(!st.empty()) {
            char top = st.top();
            st.pop();
            res = top + res;
        }
        return res;
    }
};