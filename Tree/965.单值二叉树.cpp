#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) {
            return true;
        }
        int target = root->val;
        return valid(target, root);
    }

    bool valid(int target, TreeNode* node) {
        if(!node) {
            return true;
        }
        if(node->val != target) {
            return false;
        }
        return valid(target, node->left) && valid(target, node->right);
    }
};
