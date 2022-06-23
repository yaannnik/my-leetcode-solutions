#include "TreeNode.h"

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int, int> mp;
    int maxCnt = 0;

    int dfs(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int sum = node->val + dfs(node->left) + dfs(node->right);
        mp[sum]++;
        maxCnt = max(maxCnt, mp[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        dfs(root);
        vector<int> ans;
        for (auto &[s, c]: mp) {
            if (c == maxCnt) {
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};
