#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;

        dfs(n, k, tmp, 0);
        return res;
    }

    void dfs(int n, int k, vector<int>& tmp, int idx) {
        if(tmp.size() == k) {
            res.emplace_back(tmp);
            return;
        }

        for(int i = idx; i < n - (k - tmp.size() -1); i++) {
            tmp.emplace_back(i+1);
            dfs(n, k, tmp, i+1);
            tmp.erase(tmp.end()-1);
        }

    }
};