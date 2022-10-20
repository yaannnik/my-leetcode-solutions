#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int n = strs[0].size();
        for(int i = 0; i < n; i++) {
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if(strs[j][i] != ch) {
                    return prefix;
                }
            }
            prefix += ch;
        }
        return prefix;
    }
};
