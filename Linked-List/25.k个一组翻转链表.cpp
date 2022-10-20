#include <utility>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) {
            return nullptr;
        }
        ListNode *dummy = new ListNode(-1, head), *ptr = dummy;
        ListNode *begin = head, *end = begin;
        while(begin && end) {
            int length = 0;
            while(end && length < k) {
                end = end->next;
                length++;
            }
            if(length == k) {
                auto [left, right] = reverse(begin, end);
                ptr->next = left;
                ptr = right;
                begin = end;
            } else {
                ptr->next = begin;
            }
        }
        return dummy->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* begin, ListNode* end) {
        ListNode* H = new ListNode(-1, nullptr);
        ListNode* ptr = begin;
        while(ptr != end) {
            ListNode* next = ptr->next;
            ptr->next = H->next;
            H->next = ptr;
            ptr = next;
        }
        return {H->next, begin};
    }
};