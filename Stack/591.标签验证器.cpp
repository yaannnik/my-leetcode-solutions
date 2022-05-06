#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        int n = code.size();
        stack<string> st;

        int i = 0;
        while(i < n) {
            if(code[i] == '<') {
                if(i == n - 1) {
                    return false;
                }
                if(code[i+1] == '/') {
                    int j = code.find('>', i);
                    string tag = code.substr(i + 2, j - (i + 2));
                    // 如果tag不匹配
                    if(st.empty() || tag != st.top()) {
                        return false;
                    }
                    st.pop();
                    i = j + 1;
                    // 如果tag之外还有文字
                    if(st.empty() && i != n) {
                        return false;
                    }
                } else if(code[i+1] == '!') {
                    if(st.empty()) {
                        return false;
                    }
                    string cdata = code.substr(i + 2, 7);
                    if(cdata != "[CDATA[") {
                        return false;
                    }
                    int j = code.find("]]>", i);
                    if(j == string::npos) {
                        return false;
                    }
                    i = j + 1;
                } else {
                    int j = code.find('>', i);
                    if(j == string::npos) {
                        return false;
                    }
                    string tag = code.substr(i + 1, j - (i+1));
                    if(tag.size() < 1 || tag.size() > 9 || !validTag(tag)) {
                        return false;
                    }
                    st.push(tag);
                    i = j + 1;
                }
            } else {
                if(st.empty()) {
                    return false;
                }
                i++;
            }
        }
        return st.empty();
    }

    bool validTag(string tag) {
        for(char& ch : tag) {
            if(ch < 'A' || ch > 'Z') {
                return false;
            }
        }
        return true;
    }
};
