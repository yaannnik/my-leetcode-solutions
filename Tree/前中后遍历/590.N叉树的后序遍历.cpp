#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Recursive {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        if(!root) {
            return {};
        }
        helper(root);
        return res;
    }

    void helper(Node* root) {
        int n = root->children.size();
        for(int i = 0; i < n; i++) {
            postorder(root->children[i]);
        }
        res.emplace_back(root->val);
    }
};

class Traverse {
public:
    vector<int> postorder(Node* root) {
        if(!root) {
            return {};
        }
        vector<int> res;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* node = st.top();
            st.pop();
            res.emplace_back(node->val);
            for(Node* child : node->children) {
                st.push(child);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
