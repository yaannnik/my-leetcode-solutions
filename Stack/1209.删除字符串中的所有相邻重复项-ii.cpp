#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> cst; // 记录出现的字符
        stack<int> nst; // 记录cst栈顶字符连续出现的次数

        unordered_set<int> remove;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(!cst.empty() && ch == s[cst.top()]) {
                nst.top() += 1;
                cst.push(i);
                if(nst.top() == k) {
                    for(int j = 0; j < k; j++) {
                        remove.insert(cst.top());
                        cst.pop();
                    }
                    nst.pop();
                }
            } else {
                nst.push(1);
                cst.push(i);
            }
        }

        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(!remove.count(i)) {
                res += s[i];
            }
        }
        return res;
    }
};
