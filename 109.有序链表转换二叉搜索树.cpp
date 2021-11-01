/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p) {
            p = p->next;
            len++;
        }
        return dfs(head, 0, len - 1);
    }

    TreeNode* dfs(ListNode* head, int left, int right) {
        if(left <= right) {
            int mid = left + (right - left)/2;
            ListNode* p = head;
            for(int i = 0; i < mid; i++) {
                p = p->next;
            }
            TreeNode* root = new TreeNode(p->val);
            root->left = dfs(head, left, mid - 1);
            root->right = dfs(head, mid + 1, right);
            return root;
        } else {
            return nullptr;
        }
        
    }
};
// @lc code=end

