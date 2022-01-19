#include "ListNode.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        ListNode *even = new ListNode(-1, nullptr), *tmp = even;
        ListNode* ptr = head;
        //两种情况：ptr位于最后一个或者倒数第二个
        while(ptr->next && ptr->next->next) {
            tmp->next = ptr->next;
            ptr->next = ptr->next->next;
            ptr = ptr->next;
            //tmp->next置空，以防形成环形链表
            tmp = tmp->next;
            tmp->next = nullptr;
        }
        //位于倒数第二个时，要把最后一个也带上
        if(ptr->next) {
            tmp->next = ptr->next;
            tmp = tmp->next;
        }
        ptr->next = even->next;
        return head;
    }
};
