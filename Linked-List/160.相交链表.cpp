struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) {
            return nullptr;
        }
        ListNode* ptrA = headA, *ptrB = headB;
        int lenA = ListLen(ptrA);
        int lenB = ListLen(ptrB);

        ptrA = headA;
        ptrB = headB;

        //向后移abs(lenA-lenB)，位于同样的起点
        if(lenA > lenB) {
            for(int i = 0; i < lenA-lenB; i++) {
                ptrA = ptrA->next;
            }
        } else {
            for(int i = 0; i < lenB-lenA; i++) {
                ptrB = ptrB->next;
            }
        }

        while(ptrA && ptrB) {
            if(ptrA == ptrB) {
                return ptrA;
            } else {
                ptrA = ptrA->next;
                ptrB = ptrB->next;
            }
        }
        return nullptr;
    }

    int ListLen(ListNode* ptr) {
        int res = 0;
        while(ptr) {
            res++;
            ptr = ptr->next;
        }
        return res;
    }
};
