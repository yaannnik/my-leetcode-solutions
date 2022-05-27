#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *a1, *a2;
        ListNode* dummy = new ListNode(-1, list1);
        ListNode* ptr = dummy;
        for(int i = 0; i <= b + 1; i++) {
            ptr = ptr->next;
            if(i == a - 1) {
                a1 = ptr;
            }
        }
        a2 = ptr;

        ptr = list2;
        while(ptr->next) {
            ptr = ptr->next;
        }

        a1->next = list2;
        ptr->next = a2;

        return dummy->next;
    }
};
