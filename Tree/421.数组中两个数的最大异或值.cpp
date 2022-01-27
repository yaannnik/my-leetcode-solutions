#include <vector>
using namespace std;

struct Node {
    vector<Node*> next;
    Node() {
        next = vector<Node*>(2, nullptr);
    }
};

class Solution {
public:
    void insert(int num, Node* root) {
        for(int i = 30; i >= 0; i--) {
            int t = (num >> i) & 1;
            if(!root->next[t]) {
                root->next[t] = new Node();
            }
            root = root->next[t];
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        for(int& num : nums) {
            insert(num, root);
        }
        int res = 0, tmp = 0;
        Node* p = root;
        for(int& num : nums) {
            p = root;
            tmp = 0;
            for(int i = 30; i >= 0; i--) {
                int t = (num >> i) & 1;
                if(p->next[!t]) {
                    p = p->next[!t];
                    tmp += (1 << i);
                } else {
                    p = p->next[t];
                }
            }
            res = max(res, tmp);
        }
        return res;
    }
};
