/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while(!st.empty() || node) {
            while(node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            if(!node->right || node->right == prev) {
                res.push_back(node->val);
                prev = node;
                node = nullptr;
            } else {
                st.push(node);
                node = node->right;
            }
        }
       return res; 
    }
};
// @lc code=end

