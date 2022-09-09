#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root) {
            dfs(root, false);
        }

        return res;
    }

    void dfs(TreeNode* node, bool left) {
        if(!node->left && !node->right) {
            res += left ? node->val : 0;
            return;
        }
        if(node->left) {
            dfs(node->left, true);
        }
        if(node->right) {
            dfs(node->right, false);
        }

    }

    int res = 0;
};
