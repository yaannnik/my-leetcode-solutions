#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); i++) {
            dfs(i, nums, tmp, 0);
        }
        return res;
    }

    void dfs(int n, vector<int>& nums, vector<int>& tmp, int idx) {
        if(tmp.size() == n) {
            res.emplace_back(tmp);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            tmp.emplace_back(nums[i]);
            dfs(n, nums, tmp, i+1);
            tmp.erase(tmp.end()-1);
        }
    }
};