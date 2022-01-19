#include <set>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        stack<int> st;
        set<int> idx; // char to skip
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')') {
                if(!st.empty()) {
                    // make pair
                    st.pop();
                } else {
                    // single ')'
                    idx.insert(i);
                }
            }
            if(s[i] == '(') {
                st.push(i);
            }
        }
        while(!st.empty()) {
            // single '('
            idx.insert(st.top());
            st.pop();
        }
        for(int i = 0; i < s.size(); i++) {
            if(idx.find(i) == idx.end()) {
                res += s[i];
            }
        }
        return res;
    }
};
