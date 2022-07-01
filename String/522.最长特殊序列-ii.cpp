#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        for(int i = 0; i < strs.size(); i++) {
            bool flag = true;
            for(int j = 0; j < strs.size(); j++) {
                if(i == j) {
                    continue;
                }
                if(helper(strs[i], strs[j])) {
                    flag = false;
                }
            }
            if(flag) {
                int l = strs[i].size();
                res = max(res, l);
            }
        }
        return res;
    }

    bool helper(string sub, string dst) {
        int p1 = 0, p2 = 0;
        while(p1 < sub.size() && p2 < dst.size()) {
            if(sub[p1] == dst[p2]) {
                p1++;
                p2++;
            } else {
                p2++;
            }
        }
        return p1 == sub.size();
    }
};
