using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        if(head->next == head) {
            head->next = new Node(insertVal, head);
            return head;
        }
        Node* ptr = head, * nex = ptr->next;
        while(nex != head) {
            if(insertVal <= nex->val && insertVal >= ptr->val) {
                break;
            }
            if(ptr->val > nex->val) {
                if(insertVal > ptr->val || insertVal < nex->val) {
                    break;
                }
            }
            ptr = ptr->next;
            nex = nex->next;
        }
        ptr->next = new Node(insertVal, nex);
        return head;
    }
};
