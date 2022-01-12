#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> getFactors(int n) {
        vector<int> tmp;
        dfs(n, tmp);
        return res;
    }

    void dfs(int k, vector<int> tmp) {
        if(k == 1) {
            if(tmp.size() > 1) {
                res.emplace_back(tmp);
            }
            return;
        }
        int s = sqrt(k);
        for(int i = 1; i <= s; i++) {
            if(i == 1) {
                tmp.emplace_back(k);
                dfs(1, tmp);
                tmp.erase(tmp.end()-1);
                continue;
            }
            if(k % i == 0) {
                if(tmp.empty() || i >= tmp.back()) {
                    tmp.emplace_back(i);
                    dfs(k / i, tmp);
                    tmp.erase(tmp.end()-1);
                } else {
                    continue;
                }
            }
        }
    }
};
