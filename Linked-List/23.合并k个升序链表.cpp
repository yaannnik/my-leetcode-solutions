#include "ListNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        int n = lists.size();
        ListNode* res = helper(lists, 0, n-1);
        return res;
    }

    ListNode* helper(vector<ListNode*>& lists, int left, int right) {
        if(left >= right) {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        ListNode* p1 = helper(lists, left, mid);
        ListNode* p2 = helper(lists, mid + 1, right);
        ListNode* res = merge(p1, p2);
        return res;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        ListNode *p1 = l1, *p2 = l2;
        ListNode *res = new ListNode(-1, nullptr), *ptr = res;
        while(p1 && p2) {
            if(p1->val <= p2->val) {
                ptr->next = p1;
                p1 = p1->next;
            } else {
                ptr->next = p2;
                p2 = p2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = p1 ? p1 : p2;
        return res->next;
    }
};