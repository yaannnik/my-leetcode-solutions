/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) 
            return head;

        ListNode* dummy = new ListNode(-101, head);
        ListNode* tmp = dummy;
        ListNode* pre = dummy;
        ListNode* p = pre->next;
        while(p->next) {
            ListNode* post = p->next;
            if(p->val != pre->val && p->val != post->val) {
                tmp->next = p;
                tmp = p;
            }
            pre = p;
            p = post;
        }
        if(p->val != pre->val) {
            tmp->next = p;
            tmp = p;
        }
        tmp->next = nullptr;
        return dummy->next;
    }
};
// @lc code=end

