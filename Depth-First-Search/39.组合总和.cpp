#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;

        dfs(candidates, tmp, target, 0);

        return res;
    }

    void dfs(vector<int>& candidates, vector<int>& tmp, int val, int idx) {
        if(val == 0) {
            res.emplace_back(tmp);
            return;
        }

        if(val < 0) {
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            tmp.emplace_back(candidates[i]);
            dfs(candidates, tmp, val - candidates[i], i);
            tmp.erase(tmp.end() - 1);
        }
    }
};