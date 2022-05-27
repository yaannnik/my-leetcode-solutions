#include "ListNode.h"
#include <stack>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        int len = 0;
        ListNode* ptr = head;
        while(ptr) {
            st.push(ptr);
            len++;
            ptr = ptr->next;
        }
        int half = len / 2;
        ptr = head;
        for(int i = 0; i < half; i++) {
            ListNode* top = st.top();
            st.pop();
            // cout << top->val << endl;
            ListNode* tmp = ptr->next;
            top->next = tmp;
            ptr->next = top;
            ptr = tmp;
        }
        ptr->next = nullptr;
    }
};
