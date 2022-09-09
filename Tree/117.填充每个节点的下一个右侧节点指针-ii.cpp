#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return nullptr;
        }
        Node* cur = root;
        while(cur) {
            Node* dummy = new Node(-1);
            Node* prev = dummy;
            while(cur) {
                if(cur->left) {
                    prev->next = cur->left;
                    prev = prev->next;
                }
                if(cur->right) {
                    prev->next = cur->right;
                    prev = prev->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
        }
        return root;
    }
};
