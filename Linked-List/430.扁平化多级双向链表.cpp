class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }

    Node* dfs(Node* node) {
        Node* ptr = node;
        Node* end = nullptr;
        while(ptr) {
            Node* next = ptr->next;
            if(ptr->child) {
                Node* child_end = dfs(ptr->child);
                ptr->next = ptr->child;
                ptr->child->prev = ptr;
                ptr->child = nullptr;
                end = child_end;

                if(next) {
                    child_end->next = next;
                    next->prev = child_end;
                }
            } else {
                end = ptr;
            }
            ptr = next;
        }
        return end;
    }
};
