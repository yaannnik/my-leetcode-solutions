#include "TreeNode.h"
#include <numeric>
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* node, long long min, long long max) {
        if(!node)
            return true;
        if(node->val <= min || node->val >= max)
            return false;
        return (dfs(node->left, min, node->val) && 
                dfs(node->right, node->val, max));

    }
};
