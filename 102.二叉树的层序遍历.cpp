/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()) {
            int l = qu.size();
            vector<int> tmp;
            for(int i = 0; i < l; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                tmp.push_back(node->val);
                if(node->left) {
                    qu.push(node->left);
                }
                if(node->right) {
                    qu.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

