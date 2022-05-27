#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        ListNode *p1 = reverse(l1), *p2 = reverse(l2);
        ListNode *res = helper(p1, p2);
        res = reverse(res);
        return res;
    }

    ListNode* helper(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        int add = 0;
        ListNode *p1 = l1, *p2 = l2;
        ListNode *dummy = new ListNode(-1, nullptr), *ptr = dummy;
        while(p1 && p2) {
            int sum = p1->val + p2->val + add;
            ptr->next = new ListNode(sum % 10, nullptr);
            add = sum / 10;
            p1 = p1->next;
            p2 = p2->next;
            ptr = ptr->next;
        }
        p1 = p1 ? p1 : p2;
        while(p1) {
            int sum = p1->val + add;
            ptr->next = new ListNode(sum % 10);
            add = sum / 10;
            p1 = p1->next;
            ptr = ptr->next;
        }
        if(add) {
            ptr->next = new ListNode(add, nullptr);
        }
        return dummy->next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* H = new ListNode(-1, nullptr);
        ListNode* ptr = head;
        ListNode* tmp;
        while(ptr) {
            tmp = ptr->next;
            ptr->next = H->next;
            H->next = ptr;
            ptr = tmp;
        }
        return H->next;
    }
};