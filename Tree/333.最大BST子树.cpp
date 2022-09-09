#include "TreeNode.h"
#include <numeric>
using namespace std;

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root) {
        if(isBST(root, INT_MIN, INT_MAX)) {
            res = max(res, treeSize(root));
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }

    bool isBST(TreeNode* root, int min, int max) {
        if(!root) {
            return true;
        }
        if(root->val >= max || root->val <= min) {
            return false;
        }
        return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
    }

    int treeSize(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + treeSize(root->left) + treeSize(root->right);
    }

    int res;
};
