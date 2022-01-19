#include "ListNode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *dummy = new ListNode(-101), *ptr = head, *pd = dummy;
        dummy->next = head;
        int pre = -101;
        while(ptr) {
            if(ptr->val != pre && (ptr->next == nullptr || ptr->val != ptr->next->val)) {
                pd->next = ptr;
                pd = ptr;
            }
            pre = ptr->val;
            ptr = ptr->next;
        }
        pd->next = ptr;
        return dummy->next;
    }
};