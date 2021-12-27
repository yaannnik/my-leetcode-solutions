#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> tmp;

        dfs(nums, tmp, visited);

        return res;
    }

    void dfs(vector<int>& nums, vector<int>& tmp, vector<bool>& visited) {
        if(tmp.size() == nums.size()) {
            res.emplace_back(tmp);
        }

        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) {
                continue;
            }
            tmp.emplace_back(nums[i]);
            visited[i] = true;
            dfs(nums, tmp, visited);
            visited[i] = false;
            tmp.erase(tmp.end()-1);
        }
    }
};