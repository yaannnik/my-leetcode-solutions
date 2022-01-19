#include "ListNode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        if(!ptr) {
            return head;
        }
        while(ptr->next) {
            if(ptr->next->val == ptr->val) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};