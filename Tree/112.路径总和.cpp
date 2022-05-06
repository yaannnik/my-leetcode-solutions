#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return false;
        }
        return dfs(root, 0, targetSum);
    }

    bool dfs(TreeNode* node, int tempSum, int targetSum) {
        if(!node->left && !node->right) {
            tempSum += node->val;
            if(tempSum == targetSum) {
                return true;
            } else {
                return false;
            }
        }
        bool left = false, right = false;
        if(node->left) {
            left = dfs(node->left, tempSum + node->val, targetSum);
        }
        if(node->right) {
            right = dfs(node->right, tempSum + node->val, targetSum);
        }
        return (left || right);
    }
};
