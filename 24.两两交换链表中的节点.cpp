/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* tmp = dummy;
        while(tmp->next && tmp->next->next) {
            ListNode* node1 = tmp->next;
            ListNode* node2 = tmp->next->next;
            tmp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tmp = node1;
        }
        // head is now the second node in the linked list
        return dummy->next;
    }
};
// @lc code=end

