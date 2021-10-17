/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int length = 0;
        ListNode* p = head;
        while(p) {
            p = p->next;
            length++;
        }
        int value1 = 0, value2 = 0;
        k = k % length;
        // for(int i = 0; i < k; i++) {
            p = head;
            value1 = p->val;
            while(p->next) {
                value2 = p->next->val;
                p->next->val = value1;
                p = p->next;
                value1 = value2;
            }
            head->val = value2;
        // }
        return head;
    }
};
// @lc code=end

