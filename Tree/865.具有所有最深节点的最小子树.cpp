#include "TreeNode.h"
#include <math.h>
using namespace std;

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        int ld = dfs(root->left), rd = dfs(root->right);
        if(ld == rd) {
            return root;
        } else if(ld > rd) {
            return subtreeWithAllDeepest(root->left);
        } else {
            return subtreeWithAllDeepest(root->right);
        }
    }

    int dfs(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
};
