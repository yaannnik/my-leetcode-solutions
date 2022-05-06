#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        int len = 0;
        ListNode* p = head;
        while(p) {
            len++;
            p = p->next;
        }

        ListNode* dummy = new ListNode(-1, head);

        for(int sublen = 1; sublen < len; sublen *= 2) {
            ListNode* prev = dummy, * cur = dummy->next;
            while(cur) {
                ListNode* head1 = cur;
                for(int i = 1; i < sublen && cur->next; i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr;

                cur = head2;
                for(int i = 1; i < sublen && cur; i++) {
                    cur = cur->next;
                }

                ListNode* next = nullptr;
                if(cur) {
                    next =  cur->next;
                    cur->next = nullptr;
                }

                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while(prev->next) {
                    prev = prev->next;
                }

                cur = next;
            }
        }
        return dummy->next;
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        ListNode* pa = a, * pb = b;
        while(pa && pb) {
            if(pa->val <= pb->val) {
                p->next = pa;
                pa = pa->next;
            } else {
                p->next = pb;
                pb = pb->next;
            }
            p = p->next;
        }
        p->next = (pa == nullptr) ? pb : pa;
        return dummy->next;
    }
};
