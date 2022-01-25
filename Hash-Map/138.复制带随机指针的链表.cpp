#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> mp;
        Node *head_ = new Node(head->val);
        mp[head] = head_;
        Node *ptr = head->next, *ptr_ = head_;
        while(ptr) {
            ptr_->next = new Node(ptr->val);
            ptr_ = ptr_->next;
            mp[ptr] = ptr_;
            ptr = ptr->next;
        }
        ptr = head;
        ptr_ = head_;
        while(ptr) {
            ptr_->random = mp[ptr->random];
            ptr = ptr->next;
            ptr_ = ptr_->next;
        }
        return head_;
    }
};
