struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        //找中点的方法：奇数长度slow是中点，偶数长度slow是后一半的第一个节点
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
