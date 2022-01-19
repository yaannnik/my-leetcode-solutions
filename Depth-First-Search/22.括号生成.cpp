#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(1, 0, n, "(");
        return res;
    }

    void dfs(int left, int right, int n, string tmp) {
        if(left == n) {
            if(right == n) {
                res.emplace_back(tmp);
                return;
            } else {
                dfs(left, right + 1, n, tmp + ')');
                return;
            }
        }
        if(right < left) {
            dfs(left + 1, right, n, tmp + '(');
            dfs(left, right + 1, n, tmp + ')');
            return;
        } else {
            dfs(left + 1, right, n, tmp + '(');
            return;
        }
    }
};
