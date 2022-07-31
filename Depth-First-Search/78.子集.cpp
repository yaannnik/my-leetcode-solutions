#include <vector>
using namespace std;

class Solution1 {
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

class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int range = (1 << n) - 1;
        vector<vector<int>> res;
        for(int i = 0; i <= range; i++) {
            int x = i;
            vector<int> tmp;
            for(int j = 0; j < n; j++) {
                int bit = x & 1;
                if(bit == 1) {
                    tmp.emplace_back(nums[j]);
                }
                x >>= 1;
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};