#include "ListNode.h"
using namespace std;

class MyLinkedList {
public:
    MyLinkedList() {
        tail = new ListNode(-1, nullptr);
        dummy = new ListNode(-1, tail);
        ptr = dummy;
        length = 0;
    }

    int get(int index) {
        if(index >= length || index < 0) {
            return -1;
        }
        ptr = dummy;
        for(int i = 0; i <= index; i++) {
            ptr = ptr->next;
        }
        ListNode* p = dummy;
        while(p) {
            // cout << p->val << " ";
            p = p->next;
        }
        // cout << endl;
        return ptr->val;
    }

    void addAtHead(int val) {
        ListNode* tmp = dummy->next;
        dummy->next = new ListNode(val, tmp);
        length++;
    }

    void addAtTail(int val) {
        tail->val = val;
        tail->next = new ListNode(-1, nullptr);
        tail = tail->next;
        length++;
    }

    void addAtIndex(int index, int val) {
        if(index > length) {
            return;
        } else if (index == length) {
            addAtTail(val);
        } else if(index < 0) {
            addAtHead(val);
        } else {
            ptr = dummy;
            for(int i = 0; i <= index; i++) {
                ptr = ptr->next;
            }
            ListNode* tmp = ptr->next;
            ptr->next = new ListNode(ptr->val, tmp);
            ptr->val = val;
            length++;
        }
    }

    void deleteAtIndex(int index) {
        if(index >= length) {
            return;
        }
        ptr = dummy;
        for(int i = 0; i <= index - 1; i++) {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        length--;
    }

    ListNode *dummy, *tail;
    ListNode* ptr;
    int length;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
