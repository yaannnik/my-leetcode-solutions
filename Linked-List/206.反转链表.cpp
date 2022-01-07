struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        ListNode* H = new ListNode(-1, nullptr), *ptr = head;
        while(ptr) {
            ListNode* n = ptr->next;
            ptr->next = H->next;
            H->next = ptr;
            ptr = n;
        }
        return H->next;
    }
};