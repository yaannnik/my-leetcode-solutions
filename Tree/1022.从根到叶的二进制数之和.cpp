#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int res;
    int sumRootToLeaf(TreeNode* root) {
        if(!root) {
            return 0;
        }
        res = 0;
        dfs(0, root);
        return res;
    }

    void dfs(int val, TreeNode* node) {
        if(!node->left && !node->right) {
            res += ((val << 1) + node->val);
        }
        val = (val << 1) + node->val;
        if(node->left) {
            dfs(val, node->left);
        }
        if(node->right) {
            dfs(val, node->right);
        }
    }
};
