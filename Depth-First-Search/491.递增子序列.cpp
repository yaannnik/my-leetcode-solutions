#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tmp;
        dfs(nums, tmp, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void dfs(vector<int>& nums, vector<int>& tmp, int idx) {
        if(tmp.size() > 1) {
            res.emplace_back(tmp);
        }
        vector<bool> used(201, false);
        for(int i = idx; i < nums.size(); i++) {
            if(tmp.empty() || nums[i] >= tmp.back()) {
                if(!used[nums[i]+100]) {
                    used[nums[i]+100] = true;
                    tmp.emplace_back(nums[i]);
                    dfs(nums, tmp, i + 1);
                    tmp.erase(tmp.end()-1);
                }
            }
        }
    }
};
