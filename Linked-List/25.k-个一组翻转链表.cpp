#include <utility>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(-1, head);
        ListNode *start = dummy, *end = start;
        for(int i = 0; i < k + 1; i++) {
            if(!end) {
                return dummy->next;
            }
            end = end->next;
        }

        while(start) {
            auto [p1, p2] = reverse(start->next, end);
            // cout << p1->val << " " << p2->val << endl;
            start->next = p1;
            p2->next = end;
            start = p2;
            end = start;
            for(int i = 0; i < k + 1; i++) {
                if(!end) {
                    return dummy->next;
                }
                end = end->next;
            }
        }

        return dummy->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* start, ListNode* end) {
        ListNode* H = new ListNode(-1, nullptr);
        ListNode* ptr = start;
        while(ptr != end) {
            ListNode* tmp = ptr->next;
            ptr->next = H->next;
            H->next = ptr;
            ptr = tmp;
        }
        return {H->next, start};
    }
};