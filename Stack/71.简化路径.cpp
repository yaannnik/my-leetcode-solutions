#include <string>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string dir = "";
        while(getline(ss, dir, '/')) {
            if(dir == "" || dir == ".") {
                continue;
            } else if(dir == "..") {
                if(!st.empty()) {
                    st.pop();
                } else {
                    continue;
                }
            } else {
                dir = "/" + dir;
                st.push(dir);
            }
        }
        string res = "";
        while(!st.empty()) {
            string tmp = st.top();
            st.pop();
            res = tmp + res;
        }
        return res == "" ? "/" : res;
    }
};
