#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        int sign = 1;
        signs.push(1);

        int res = 0;
        int i = 0;
        while(i < s.size()) {
            if(s[i] == ' ') {
                i++;
            } else if(s[i] == '+') {
                sign = signs.top();
                i++;
            } else if(s[i] == '-') {
                sign = -signs.top();
                i++;
            } else if(s[i] == '(') {
                signs.push(sign);
                i++;
            } else if(s[i] == ')') {
                signs.pop();
                i++;
            } else {
                long num = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                res += sign * num;
            }
        }
        return res;
    }
};
