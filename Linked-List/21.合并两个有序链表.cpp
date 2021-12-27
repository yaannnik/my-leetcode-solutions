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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode(-1);
        ListNode* p1 = list1, * p2 = list2, * pr = res;

        while(p1 && p2) {
            if(p1->val <= p2->val) {
                pr->next = new ListNode(p1->val);
                p1 = p1->next;
            } else {
                pr->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            pr = pr->next;
        }

        pr->next = p1 ? p1 : p2;

        return res->next;
    }
};