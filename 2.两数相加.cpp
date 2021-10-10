/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        ListNode* res = new ListNode(-1);
        ListNode* p1 = l1, * p2 = l2;
        ListNode* p  = res;
        int add = 0;
        while(l1 && l2) {
            int sum = l1->val + l2->val + add;
            add = sum/10;
            p->next = new ListNode(sum%10);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* remain = l1 ? l1 : l2;
        while(remain) {
            int sum = remain->val + add;
            add = sum/10;
            p->next = new ListNode(sum%10);
            p = p->next;
            remain = remain->next;
        }
        if(add) {
            p->next = new ListNode(add);
        }
        return res->next;
    }
};
// @lc code=end

