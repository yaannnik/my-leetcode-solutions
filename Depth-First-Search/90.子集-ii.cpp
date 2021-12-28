#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); i++) {
            dfs(i, nums, tmp, visited, 0);
        }
        return res;
    }

    void dfs(int n, vector<int>& nums, vector<int>& tmp, vector<bool>& visited, int idx) {
        if(tmp.size() == n) {
            res.emplace_back(tmp);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            if(i > 0 && !visited[i-1] && nums[i] == nums[i-1]) {
                continue;
            }
            tmp.emplace_back(nums[i]);
            visited[i] = true;
            dfs(n, nums, tmp, visited, i+1);
            visited[i] = false;
            tmp.erase(tmp.end()-1);
        }
    }
};
