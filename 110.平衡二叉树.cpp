/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
// @lc code=end

