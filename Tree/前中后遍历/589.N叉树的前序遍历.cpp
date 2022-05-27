#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// Definition for a Node.
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
    vector<int> preorder(Node* root) {
        if(!root) {
            return res;
        }
        res.emplace_back(root->val);
        for(int i = 0; i < root->children.size(); i++) {
            preorder(root->children[i]);
        }
        return res;
    }
};

class Traverse1 {
public:
    unordered_map<Node*, int> mp;
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) {
            return res;
        }
        stack<Node*> st;
        while(root || !st.empty()) {
            while(root) {
                if(!mp.count(root)) {
                    mp[root] = 0;
                }
                res.emplace_back(root->val);
                st.push(root);
                if(!root->children.empty()) {
                    root = root->children[mp[root]];
                } else {
                    root = nullptr;
                }
            }
            root = st.top();
            mp[root]++;
            if(mp[root] >= root->children.size()) {
                st.pop();
                root = nullptr;
            } else {
                root = root->children[mp[root]];
            }
        }
        return res;
    }
};

class Traverse2 {
public:
    vector<int> preorder(Node* root) {
        if(!root) {
            return {};
        }
        vector<int> res;
        stack<Node*> st;
        st.emplace(root);
        while(!st.empty()) {
            root = st.top();
            st.pop();
            res.emplace_back(root->val);
            for(auto it = root->children.rbegin(); it != root->children.rend(); it++) {
                st.emplace(*it);
            }
        }
        return res;
    }
};