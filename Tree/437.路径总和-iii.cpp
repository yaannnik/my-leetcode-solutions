#include "TreeNode.h"
#include <unordered_map>
using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return 0;
        }
        unordered_map<long, int> mp;
        dfs(root, root->val, targetSum, mp);
        return res;
    }

    void dfs(TreeNode* node, long sum, int target, unordered_map<long, int>& mp) {
        if(sum == target) {
            // cout << sum << endl;
            res++;
        }
        if(mp[sum - target] > 0) {
            // cout << sum << " " << mp[sum - target] << endl;
            res += mp[sum - target];
        }


        mp[sum]++;
        if(node->left) {
            dfs(node->left, sum + node->left->val, target, mp);
        }
        if(node->right) {
            dfs(node->right, sum + node->right->val, target, mp);
        }
        mp[sum]--;
    }

    int res = 0;
};
