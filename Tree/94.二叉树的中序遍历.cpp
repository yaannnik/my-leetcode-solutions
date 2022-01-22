#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

class Solution {
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
