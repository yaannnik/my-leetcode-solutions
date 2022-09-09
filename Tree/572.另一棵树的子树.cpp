#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) {
            return false;
        }
        return sameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* node1, TreeNode* node2) {
        if(!node1 && !node2) {
            return true;
        }
        if((!node1 && node2) || (node1 && !node2) || (node1->val != node2->val)) {
            return false;
        }
        return sameTree(node1->left, node2->left) && sameTree(node1->right, node2->right);
    }
};
