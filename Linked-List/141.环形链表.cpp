struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) {
            return false;
        }
        ListNode* slow = head, *fast = head;
        //快指针前进两步的边界条件
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};
