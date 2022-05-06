#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* tmp = dummy;
        while(tmp->next && tmp->next->next) {
            ListNode* node1 = tmp->next;
            ListNode* node2 = tmp->next->next;
            tmp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tmp = node1;
        }
        // head is now the second node in the linked list
        return dummy->next;
    }
};
