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

class Solution1 {
public:
    Node* flatten(Node* head) {
        if(!head) {
            return head;
        }
        // flatten child and next
        head->child = flatten(head->child);
        head->next = flatten(head->next);

        Node* next = head->next;

        head->next = head->child;
        if(head->next) {
            head->next->prev = head;
        }

        head->child = nullptr;

        Node* ptr = head;
        while(ptr->next) {
            ptr = ptr->next;
        }

        ptr->next = next;
        if(next) {
            next->prev = ptr;
        }

        return head;
    }
};

class Solution2 {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while(cur) {
            if(cur->child) {
                Node* tmp = cur->child;
                while(tmp->next) {
                    tmp = tmp->next;
                }
                tmp->next = cur->next;
                if(cur->next) {
                    cur->next->prev = tmp;
                }
                cur->next = cur->child;
                cur->child->prev = cur;

                cur->child = nullptr;
            }
            cur = cur->next;
        }
        return head;
    }
};
