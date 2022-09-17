#include "ListNode.h"
#include <stack>
using namespace std;

class Solution1 {
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

class Solution2 {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* ptr = head;
        while(ptr) {
            vec.push_back(ptr);
            ptr = ptr->next;
        }
        int n = vec.size();
        int left = 0, right = n - 1;
        while(left < right) {
            if(left < right) {
                vec[left]->next = vec[right];
                left++;
            }
            if(left < right) {
                vec[right]->next = vec[left];
                right--;
            }
        }
        vec[left]->next = nullptr;
    }
};
