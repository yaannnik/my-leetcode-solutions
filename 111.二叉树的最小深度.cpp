/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }

        queue<pair<TreeNode*, int>> qu;
        qu.emplace(root, 1);

        while(!qu.empty()) {
            TreeNode* node = qu.front().first;
            int depth = qu.front().second;
            qu.pop();

            if(!node->left && !node->right) {
                return depth;
            }
            if(node->left) {
                qu.emplace(node->left, depth + 1);
            }
            if(node->right) {
                qu.emplace(node->right, depth + 1);
            }
        }
        return 0;
    }
};
// @lc code=end

