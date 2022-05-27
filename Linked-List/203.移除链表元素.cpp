#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(-1, head);
        ListNode* ptr = dummy;
        while(ptr) {
            ListNode* tmp = ptr->next;
            if(tmp && tmp->val == val) {
                ptr->next = tmp->next;
            } else {
                ptr = ptr->next;
            }
        }
        return dummy->next;
    }
};
