#include "ListNode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto* res = new ListNode(-1);
        ListNode *p1 = l1, *p2 = l2, *pr = res;
        int add = 0;
        while(p1 && p2) {
            pr->next = new ListNode((p1->val + p2->val + add) % 10);
            add = (p1->val + p2->val + add) / 10;
            pr = pr->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode* tmp = p1 ? p1 : p2;
        while(tmp) {
            pr->next = new ListNode((tmp->val + add) % 10);
            add = (tmp->val + add) / 10;
            pr = pr->next;
            tmp = tmp->next;
        }

        if(add != 0) {
            pr->next = new ListNode(add);
        }

        return res->next;
    }
};