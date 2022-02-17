#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> generatePossibleNextMoves(string currentState) {
        dfs(currentState, 0);
        return res;
    }

    void dfs(string s, int cnt) {
        if(cnt == 1) {
            res.emplace_back(s);
            return;
        }
        for(int i = 0; i + 1 < s.size(); i++) {
            if(s[i] == '+' && s[i+1] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                dfs(s, cnt + 1);
                s[i] = '+';
                s[i+1] = '+';
            }
        }
    }
};
