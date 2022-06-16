#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> ops = {"+", "-", "*", "/"};
        stack<int> st;
        for(string& token : tokens) {
            if(ops.count(token)) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                // cout << a << " " << b << endl;
                switch(token[0]) {
                    case '+':
                        st.push(a + b);
                        break;
                    case '-':
                        st.push(b - a);
                        break;
                    case '*':
                        st.push(a * b);
                        break;
                    case '/':
                        st.push(b / a);
                        break;
                    default:
                        break;
                }
            } else {
                int num = stoi(token);
                st.push(num);
            }
        }
        return st.top();
    }
};
