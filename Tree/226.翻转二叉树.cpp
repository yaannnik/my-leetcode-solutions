#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        invert(root);
        return root;
    }

    void invert(TreeNode* node) {
        if(!node || !node->left && !node->right) {
            return;
        }

        TreeNode* left = node->left;
        node->left = node->right;
        node->right = left;

        invert(node->left);
        invert(node->right);


        return;
    }
};
