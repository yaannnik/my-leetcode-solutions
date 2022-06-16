#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        int num = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }
            if(((s[i] < '0' || s[i] > '9') && s[i] != ' ') || i == n - 1) {
                switch(sign) {
                    case '+':
                        st.push(num);
                        break;
                    case '-':
                        st.push(-num);
                        break;
                    case '*':
                        st.top() *= num;
                        break;
                    case '/':
                        st.top() /= num;
                        break;
                    default:
                        break;
                }
                sign = s[i];
                num = 0;
            }
        }
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
