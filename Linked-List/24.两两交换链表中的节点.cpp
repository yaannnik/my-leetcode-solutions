#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(-1, head);
        ListNode *start = dummy, *end = start;
        for(int i = 0; i < 3; i++) {
            end = end->next;
        }
        while(start) {
            auto [n1, n2] = reverse(start->next, start->next->next);
            start->next = n1;
            n2->next = end;
            start = n2;
            end = start;
            for(int i = 0; i < 3; i++) {
                if(!end) {
                    return dummy->next;
                }
                end = end->next;
            }
        }
        return dummy->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* first, ListNode* second) {
        first->next = nullptr;
        second->next = first;
        return {second, first};
    }
};
