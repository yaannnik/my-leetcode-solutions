/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            // pop out the inorder node
            root = st.top();
            st.pop();
            if(pred && pred->val > root->val) {
                // the last wrong place
                y = root;
                if(!x) {
                    // the first wrong place
                    x = pred;
                }
                else {
                    break;
                }
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
};
// @lc code=end

