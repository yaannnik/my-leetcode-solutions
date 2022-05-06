#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = new ListNode(-1, head);
        ListNode* slow = tmp, * fast = head;
        // fast is ahead of slow by n+1 nodes, slow -- (n nodes) -- fast
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        ListNode* ans = tmp->next;
        delete tmp;
        return ans;
    }
};
