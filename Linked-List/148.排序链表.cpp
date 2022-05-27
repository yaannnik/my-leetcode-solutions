#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* res = mergeSort(head);
        return res;
    }

    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *slow = new ListNode(-1, head), *fast = new ListNode(-1, head);
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *p1 = head, *p2 = slow->next;
        slow->next = nullptr;

        ListNode *p1_ = mergeSort(p1), *p2_ = mergeSort(p2);

        ListNode* res = merge(p1_, p2_);
        return res;
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode *p1 = a, *p2 = b;
        ListNode* res = new ListNode(-1, nullptr);
        ListNode* ptr = res;
        while(p1 && p2) {
            if(p1->val <= p2->val) {
                ptr->next = p1;
                p1 = p1->next;
            } else {
                ptr->next = p2;
                p2 = p2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = p1 ? p1 : p2;

        return res->next;
    }
};
