/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
// @lc code=end

