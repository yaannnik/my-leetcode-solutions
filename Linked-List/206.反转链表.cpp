#include "ListNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        ListNode *H = new ListNode(-1, nullptr), *ptr = head;
        while(ptr) {
            ListNode* n = ptr->next;
            ptr->next = H->next;
            H->next = ptr;
            ptr = n;
        }
        return H->next;
    }
};