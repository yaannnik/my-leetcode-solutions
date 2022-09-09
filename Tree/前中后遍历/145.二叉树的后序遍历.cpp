#include "../TreeNode.h"
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while(!st.empty() || node) {
            while(node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            if(!node->right || node->right == prev) {
                res.push_back(node->val);
                prev = node;
                node = nullptr;
            } else {
                st.push(node);
                node = node->right;
            }
        }
       return res; 
    }
};

class Traverse1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            root = st.top();
            st.pop();
            res.emplace_back(root->val);
            if(root->left) {
                st.push(root->left);
            }
            if(root->right) {
                st.push(root->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Recursion {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }

        if(root->left) {
            postorderTraversal(root->left);
        }
        if(root->right) {
            postorderTraversal(root->right);
        }
        res.emplace_back(root->val);
        return res;
    }

    vector<int> res;
};
