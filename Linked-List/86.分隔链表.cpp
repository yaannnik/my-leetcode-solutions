struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-1, head), *ptr = dummy;
        ListNode* res = new ListNode(-1), *tmp = res;
        while(ptr->next) {
            if(ptr->next->val < x) {
                tmp->next = ptr->next;
                ptr->next = ptr->next->next;
                tmp = tmp->next;
            } else {
                ptr = ptr->next;
            }
        }
        tmp->next = dummy->next;
        return res->next;
    }
};