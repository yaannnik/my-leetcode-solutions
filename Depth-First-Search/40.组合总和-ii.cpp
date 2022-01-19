#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

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
            // 不为遍历到的第一个值且重复的才跳过，这是在同一层dfs内跳过
            if(i != idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            tmp.emplace_back(candidates[i]);
            dfs(candidates, tmp, val - candidates[i], i+1);
            tmp.erase(tmp.end()-1);
        }
    }
};