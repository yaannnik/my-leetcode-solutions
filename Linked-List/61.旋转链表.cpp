#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int length = 0;
        ListNode* p = head;
        while(p) {
            p = p->next;
            length++;
        }
        int value1 = 0, value2 = 0;
        k = k % length;
        // for(int i = 0; i < k; i++) {
            p = head;
            value1 = p->val;
            while(p->next) {
                value2 = p->next->val;
                p->next->val = value1;
                p = p->next;
                value1 = value2;
            }
            head->val = value2;
        // }
        return head;
    }
};
