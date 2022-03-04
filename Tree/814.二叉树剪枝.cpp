#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0) {
            if(!root->left && !root->right) {
                return nullptr;
            }
        }
        return root;
    }
};
