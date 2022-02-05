#include "ListNode.h"
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        queue<ListNode*> qu;
        for(ListNode* p : lists) {
            qu.push(p);
        }
        while(qu.size() > 1) {
            ListNode* p1 = qu.front();
            qu.pop();
            ListNode* p2 = qu.front();
            qu.pop();
            ListNode* np = mergeTwoLists(p1, p2);
            qu.push(np);
        }
        return qu.front();
    }

    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        while(p1 && p2) {
            if(p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        while(p1) {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        while(p2) {
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
        return dummy->next;
    }
};
