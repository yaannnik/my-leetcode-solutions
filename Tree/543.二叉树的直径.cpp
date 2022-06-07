#include "TreeNode.h"
#include <numeric>
using namespace std;

class Solution {
public:
    int res;
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        depth(root);
        return res;
    }

    int depth(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int left = depth(root->left);
        int right = depth(root->right);

        res = max(res, left + right);

        return max(left, right) + 1;
    }
};
