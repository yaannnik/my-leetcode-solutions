#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head;
        int k1 = 0, k2 = 0;
        for(int i = 0; i < k; i++) {
            ptr2 = ptr2->next;
        }
        while(ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        k2 = ptr1->val;
        ptr2 = head;
        for(int i = 0; i < k - 1; i++) {
            ptr2 = ptr2->next;
        }
        k1 = ptr2->val;
        ptr1->val = k1;
        ptr2->val = k2;
        return head;
    }
};
