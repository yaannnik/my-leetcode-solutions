#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int res = 0;
    int maxUniqueSplit(string s) {
        if(s.empty()) {
            return res;
        }
        unordered_set<string> str;
        dfs(s, str, 0);
        return res;
    }

    void dfs(string& s, unordered_set<string> str, int idx) {
        if(idx == s.size()) {
            res = max(res, (int)str.size());
            return;
        }
        for(int i = idx; i < s.size(); i++) {
            if(!str.count(s.substr(idx, i-idx+1))) {
                str.insert(s.substr(idx, i-idx+1));
                dfs(s, str, i + 1);
                str.erase(s.substr(idx, i-idx+1));
            }
        }
    }
};
