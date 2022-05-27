#include "ListNode.h"
#include <utility>
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) {
            return head;
        }
        ListNode* dummy = new ListNode(-1, head);
        ListNode* ptr = dummy;
        ListNode *p1, *p2;
        for(int i = 0; i < right; i++) {
            if(i == left - 1) {
                p1 = ptr;
            }
            ptr = ptr->next;
        }
        p2 = ptr;
        // cout << p1->val << " " << p2->val << endl;
        ListNode *start = p1->next, *end = p2->next;
        auto [t1, t2] = reverse(start, end);
        p1->next = t1;
        t2->next = end;
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
        // cout << H->next->val << " " << start->val << endl;
        return {H->next, start};
    }
};
