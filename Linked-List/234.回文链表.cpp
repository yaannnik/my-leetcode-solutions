struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) {
            return true;
        }
        ListNode* slow = head, *fast = head;
        ListNode* H = new ListNode(-1, nullptr);
        //翻转前半个链表
        while(fast && fast->next) {
            fast = fast->next->next;

            ListNode* nex = slow->next;
            slow->next = H->next;
            H->next = slow;
            slow = nex;
        }
        //对应奇数长度的链表，slow后移一位
        if(fast) {
            slow = slow->next;
        }
        ListNode* p1 = H->next, *p2 = slow;
        while(p2) {
            if(p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
