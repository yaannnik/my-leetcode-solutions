#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* l, TreeNode* r) {
        if(!l && !r)
            return true;
        if(l && r && l->val == r->val) {
            return (dfs(l->left, r->right) && dfs(l->right, r->left));
        }
        return false;
    }
};
