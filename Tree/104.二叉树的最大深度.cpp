#include "TreeNode.h"
#include <math.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(dfs(root->left, 1), dfs(root->right, 1));
    }

    int dfs(TreeNode* node, int depth) {
        if(!node)
            return depth;
        depth++;
        return max(dfs(node->left, depth), dfs(node->right, depth));
    }
};
