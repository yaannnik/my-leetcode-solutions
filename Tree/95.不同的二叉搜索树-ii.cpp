#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }

    vector<TreeNode*> helper(int left, int right) {
        if(left > right) {
            return {nullptr};
        }
        vector<TreeNode*> roots;
        for(int r = left; r <= right; r++) {
            auto lefts = helper(left, r - 1);
            auto rights = helper(r + 1, right);
            for(auto lt : lefts) {
                for(auto rt : rights) {
                    TreeNode* root = new TreeNode(r);
                    root->left = lt;
                    root->right = rt;
                    roots.emplace_back(root);
                }
            }
        }
        return roots;
    }
};
