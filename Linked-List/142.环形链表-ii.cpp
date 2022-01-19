#include <unordered_set>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> nodes;
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                ListNode *p1 = head, *p2 = slow;
                while(p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p1;
            }
        }
        return nullptr;
    }
};
