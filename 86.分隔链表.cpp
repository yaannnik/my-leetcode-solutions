/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* small = new ListNode(-101);
        ListNode* large = new ListNode(-101);
        ListNode* p_small = small;
        ListNode* p_large = large;
        while(head) {
            if(head->val < x) {
                p_small->next = new ListNode(head->val);
                p_small = p_small->next;
            } else {
                p_large->next = new ListNode(head->val);
                p_large = p_large->next;
            }
            head = head->next;
        }
        p_small->next = large->next;
        return small->next;
    }
};
// @lc code=end

