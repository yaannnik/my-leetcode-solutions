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
        ListNode* H = new ListNode(-1, nullptr);
        ListNode* ptr = head;
        while(ptr) {
            ListNode* tmp = ptr;
            ptr = ptr->next;
            tmp->next = H->next;
            H->next = tmp;
        }
        return H->next;
    }
};
// @lc code=end

