#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int> tmp;

        dfs(nums, tmp, visited);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& tmp, vector<bool>& visited) {
        if(tmp.size() == nums.size()) {
            res.emplace_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            // 如果有重复的数字，只能用第一个
            if(visited[i] || (i > 0 && !visited[i-1] && nums[i] == nums[i-1])) {
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