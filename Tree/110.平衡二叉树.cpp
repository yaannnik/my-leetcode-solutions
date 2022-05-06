#include "TreeNode.h"
#include <numeric>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }
        return abs(maxHeight(root->left, 1) - maxHeight(root->right, 1)) <=1 
                && isBalanced(root->left) 
                && isBalanced(root->right);
    }

    int maxHeight(TreeNode* root, int depth) {
        if(!root) {
            return depth;
        }
        depth += 1;
        return max(maxHeight(root->left, depth), maxHeight(root->right, depth));
    }
};
