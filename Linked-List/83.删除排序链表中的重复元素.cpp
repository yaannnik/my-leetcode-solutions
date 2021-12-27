struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        if(!ptr) {
            return head;
        }
        while(ptr->next) {
            if(ptr->next->val == ptr->val) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};