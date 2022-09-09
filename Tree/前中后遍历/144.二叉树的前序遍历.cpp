#include <vector>
#include <stack>
#include "../TreeNode.h"
using namespace std;

class Traverse {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> res;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                res.emplace_back(root->val);
                root = root->left;
            }
            root = st.top();
            st.pop();
            root = root->right;
        }
        return res;
    }
};

class Recursion {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        res.emplace_back(root->val);
        if(root->left) {
            preorderTraversal(root->left);
        }
        if(root->right) {
            preorderTraversal(root->right);
        }
        return res;
    }

    vector<int> res;
};
