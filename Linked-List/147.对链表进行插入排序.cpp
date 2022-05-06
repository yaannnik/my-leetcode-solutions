#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* lastSort = head;
        ListNode* cur = head->next;
        while(cur) {
            if(lastSort->val <= cur->val) {
                lastSort = lastSort->next;
            } else {
                ListNode* p = dummy;
                while(p->next->val <= cur->val) {
                    p = p->next;
                }
                lastSort->next = cur->next;
                cur->next = p->next;
                p->next = cur;
            }
            cur = lastSort->next;
        }
        return dummy->next;
    }
};
