/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return {};
        }
        vector<int> path;
        dfs(root, 0, targetSum, path);
        return res;
    }

    void dfs(TreeNode* node, int tempSum, int targetSum, vector<int> path) {
        if(!node->left && !node->right) {
            if(tempSum + node->val == targetSum) {
                path.push_back(node->val);
                res.push_back(path);
                return;
            } else {
                return;
            }
        }
        path.push_back(node->val);
        if(node->left) {
            dfs(node->left, tempSum + node->val, targetSum, path);
        }
        if(node->right) {
            dfs(node->right, tempSum + node->val, targetSum, path);
        }
    }
};
// @lc code=end

