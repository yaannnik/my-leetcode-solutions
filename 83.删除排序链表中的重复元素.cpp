/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        if(!head) return head;
        ListNode* node1 = head;
        while(node1->next) {
            ListNode* node2 = node1->next;
            if(node2->val == node1->val) {
                node1->next = node2->next;
                delete node2;
            } else {
                node1 = node2;
            }
        }
        return head;
    }
};
// @lc code=end

