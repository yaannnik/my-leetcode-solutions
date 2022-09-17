#include "TreeNode.h"
#include <numeric>
using namespace std;

class Solution1 {
public:
    int largestBSTSubtree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root) {
        if(isBST(root, INT_MIN, INT_MAX)) {
            res = max(res, treeSize(root));
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }

    bool isBST(TreeNode* root, int min, int max) {
        if(!root) {
            return true;
        }
        if(root->val >= max || root->val <= min) {
            return false;
        }
        return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
    }

    int treeSize(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + treeSize(root->left) + treeSize(root->right);
    }

    int res;
};

class Solution2 {
public:
    int largestBSTSubtree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        auto [min, max, size] = helper(root);
        return size;
    }


    // [min_val, max_val, max_size]
    tuple<int, int, int> helper(TreeNode* root) {
        if(!root) {
            return {INT_MAX, INT_MIN, 0};
        }

        auto [left_min, left_max, left_size] = helper(root->left);
        auto [right_min, right_max, right_size] = helper(root->right);

        if(left_max < root->val && root->val < right_min) {
            return {min(left_min, root->val), max(right_max, root->val), left_size + right_size + 1};
        }

        return {INT_MIN, INT_MAX, max(left_size, right_size)};
    }
};
