#include<stack>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size(), i = 0;
        stack<char> st;
        unordered_set<char> se;
        string res = "";
        while(i < n) {
            //如果栈内已经出现过i-th就不入栈
            if(se.find(s[i]) != se.end()) {
                i++;
                continue;
            }
            //如果i-th比栈顶元素小，且之后的子串还会有栈顶元素，则出栈
            while(!st.empty() && s[i] < st.top() && s.substr(i).find(st.top()) != string::npos) {
                se.erase(st.top());
                st.pop();

            }
            st.push(s[i]);
            se.insert(s[i]);
            i++;
        }
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
