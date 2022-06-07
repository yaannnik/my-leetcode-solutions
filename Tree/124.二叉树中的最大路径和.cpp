#include "TreeNode.h"
#include <numeric>
using namespace std;

class Solution {
public:
    int res;
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        nodeGain(root);
        return res;
    }

    int nodeGain(TreeNode* root) {
        // 单侧路径的最大贡献
        if(!root) {
            return 0;
        }
        int leftGain = max(nodeGain(root->left), 0);
        int rightGain = max(nodeGain(root->right), 0);
        int treeGain = root->val + leftGain + rightGain;
        res = max(res, treeGain);

        return max(leftGain, rightGain) + root->val;
    }
};
