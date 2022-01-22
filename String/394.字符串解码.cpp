#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        int mul = 0;
        stack<int> numst;
        stack<string> strst;
        string cur, res = "";
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                mul = mul * 10 + (s[i] - '0');
            }
            else if(s[i] == '[') {
                numst.push(mul);
                strst.push(cur);
                mul = 0;
                cur.clear();
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                cur += s[i];
            }
            else if(s[i] == ']') {
                int k = numst.top();
                numst.pop();
                for(int j = 0; j < k; j++) {
                    strst.top() += cur;
                }
                cur = strst.top();
                strst.pop();
            }
        }
        res += cur;
        return res;
    }

    string decodeString_(string s) {
        stack<char> st;
        for(char & i : s) {
            if(i != '}') {
                st.push(i);
            } else {
                string mul_ = "";
                while(!st.empty() && isdigit(st.top())) {
                    mul_ = st.top() + mul_;
                    st.pop();
                }
                st.pop(); // pop '{'
                st.pop(); // pop ')'
                int mul = stoi(mul_);
                string cur = "";
                while(st.top() != '(') {
                    cur = st.top() + cur;
                    st.pop();
                }
                st.pop(); // pop '('

                for(int i = 0; i < mul; i++) {
                    for(char & p : cur) {
                        st.push(p);
                    }
                }
            }
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};