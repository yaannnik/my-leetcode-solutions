/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* new_head = head;
        ListNode* p = nullptr;
        ListNode* n = new_head->next;
        while(n != nullptr) {
            new_head->next = p;
            p = new_head;
            new_head = n;
            n = n->next;
        }
        new_head->next = p;
        return new_head;
    }
};
// @lc code=end

