#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> sv;
        stack<string> st;
        stringstream ss(input);
        string file;
        while(getline(ss, file, '\n')) {
            // cout << file << endl;
            sv.emplace_back(file);
        }
        int len = sv[0].size(), res = isFile(sv[0]) ? len : 0;
        st.push(sv[0]);
        for(int i = 1; i < sv.size(); i++) {
            int l = layer(sv[i]);
            while(!st.empty() && l <= layer(st.top())) {
                int file_len = st.top().size() - layer(st.top());
                len -= file_len;
                st.pop();
            }
            len += (sv[i].size() - l);
            st.push(sv[i]);
            if(isFile(st.top())) {
                res = max(int(len + st.size() - 1), res);
            }
        }
        return res;
    }

    int layer(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '\t') {
                return i;
            }
        }
        return 0;
    }

    bool isFile(string s) {
        return s.find('.') != string::npos;
    }
};
