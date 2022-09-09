#include "TreeNode.h"
#include <stack>
using namespace std;

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            // pop out the inorder node
            root = st.top();
            st.pop();

            if(pred && pred->val > root->val) {
                // the last wrong place
                y = root;
                if(!x) {
                    // the first wrong place
                    x = pred;
                }
                else {
                    break;
                }
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
};
