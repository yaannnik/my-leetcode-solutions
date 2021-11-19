/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* lastSort = head;
        ListNode* cur = head->next;
        while(cur) {
            if(lastSort->val <= cur->val) {
                lastSort = lastSort->next;
            } else {
                ListNode* p = dummy;
                while(p->next->val <= cur->val) {
                    p = p->next;
                }
                lastSort->next = cur->next;
                cur->next = p->next;
                p->next = cur;
            }
            cur = lastSort->next;
        }
        return dummy->next;
    }
};
// @lc code=end

