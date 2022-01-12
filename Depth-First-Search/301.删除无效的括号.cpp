#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                l++;
            }
            else if(s[i] == ')') {
                if(l > 0) {
                    l--;
                } else {
                    r++;
                }
            }
        }
        dfs(s, l ,r, 0);
        return res;
    }

    void dfs(string tmp, int l, int r, int idx) {
        if(l == 0 && r == 0 && isValid(tmp)) {
            res.emplace_back(tmp);
            return;
        }
        for(int i = idx; i < tmp.size(); i++) {
            //连续重复的只要尝试第一个就可以
            if(i > idx && tmp[i] == tmp[i-1]) {
                continue;
            }
            //如果要删去的的比从i开始剩余的的还多，不可能存在
            if(l + r > tmp.size() - i) {
                return;
            }
            if(l > 0 && tmp[i] == '(') {
                dfs(tmp.substr(0, i) + tmp.substr(i+1), l-1, r, i);
            }
            if(r > 0 && tmp[i] == ')') {
                dfs(tmp.substr(0, i) + tmp.substr(i+1), l, r-1, i);
            }
        }
    }

    bool isValid(string& s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                cnt++;
            }
            else if(s[i] == ')') {
                cnt--;
                if(cnt < 0) {
                    return false;
                }
            }
        }
        return cnt == 0;
    }
};
