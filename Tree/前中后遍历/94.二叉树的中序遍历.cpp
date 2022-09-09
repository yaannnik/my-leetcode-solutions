#include <vector>
#include <stack>
#include "../TreeNode.h"
using namespace std;

class Traverse {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> res;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res.emplace_back(root->val);
            root = root->right;
        }
        return res;
    }
};

class Recursion {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        if(root->left) {
            inorderTraversal(root->left);
        }
        res.emplace_back(root->val);
        if(root->right) {
            inorderTraversal(root->right);
        }
        return res;
    }
    vector<int> res;
};
