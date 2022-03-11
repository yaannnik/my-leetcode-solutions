#include <vector>
#include <stack>
#include <map>
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
    vector<int> preorder(Node* root) {
        if(!root) {
            return {};
        }
        vector<int> res;
        stack<Node*> st;
        map<Node*, int> mp;
        while(!st.empty() || root) {
            while(root) {
                st.emplace(root);
                res.emplace_back(root->val);
                mp[root] = 0;
                if(!root->children.empty()) {

                    root = root->children[0];
                } else {
                    root = nullptr;
                }
            }
            root = st.top();
            int idx = mp.count(root) ? mp[root] + 1 : 0;
            if(idx < root->children.size()) {
                mp[root] = idx;
                root = root->children[idx];
            } else {
                st.pop();
                mp.erase(root);
                root = nullptr;
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