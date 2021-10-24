/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> qu;
        qu.push(root);
        int layer = 1;
        while(!qu.empty()) {
            int len = qu.size();
            deque<int> levelList;
            for(int i = 0; i < len; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                if(layer % 2 == 0) {
                    levelList.push_front(node->val);
                } else {
                    levelList.push_back(node->val);
                }
                if(node->left) {
                    qu.push(node->left);
                }
                if(node->right) {
                    qu.push(node->right);
                }
            }
            res.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            layer++;
        }
        return res;  
    }
};
// @lc code=end

