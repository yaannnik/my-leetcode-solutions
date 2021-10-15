/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) 
            return nullptr;
        return mergeInPairs(lists, 0, lists.size() - 1);
    }

    ListNode* mergeInPairs(vector<ListNode*>& lists, int left, int right) {
        if(left == right)
            return lists[left];
        else if(left > right)
            return nullptr;

        int mid = left + ((right - left) >> 1);
        return mergeTwoLists(mergeInPairs(lists, left, mid), mergeInPairs(lists, mid+1, right));
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(!a || !b) {
            return a ? a : b;
        }
        ListNode* p1 = a, * p2 = b;
        ListNode* head = new ListNode(-1);
        ListNode* p = head;

        while(p1 && p2) {
            if(p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = p1 ? p1 : p2;
        return head->next;
    }
};
// @lc code=end

