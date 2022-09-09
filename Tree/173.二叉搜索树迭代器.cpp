#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        ptr = -1;
        this->root = root;
        while(this->root || !st.empty()) {
            while(this->root) {
                st.push(this->root);
                this->root = this->root->left;
            }
            this->root = st.top();
            st.pop();
            vals.emplace_back(this->root->val);
            this->root = this->root->right;
        }
    }

    int next() {
        ptr++;
        return ptr < vals.size() ? vals[ptr] : -1;
    }

    bool hasNext() {
        return ptr + 1 < vals.size();
    }

    TreeNode* root;
    stack<TreeNode*> st;
    vector<int> vals;
    int ptr;
};

class BSTIterator1 {
public:
    BSTIterator1(TreeNode* root) {
        cur = root;
    }

    int next() {
        while(cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        int res = cur->val;
        cur = cur->right;
        return res;
    }

    bool hasNext() {
        return cur != nullptr || !st.empty();
    }

    TreeNode* cur;
    stack<TreeNode*> st;
};

class BSTPreIterator {
public:
    BSTPreIterator(TreeNode* root) {
        st.push(root);
    }

    int next() {
        cur = st.top();
        st.pop();
        int res = cur->val;
        if(cur->right) {
            st.push(cur->right);
        }
        if(cur->left) {
            st.push(cur->left);
        }
        return res;
    }

    bool hasNext() {
        return !st.empty();
    }

    TreeNode* cur;
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
