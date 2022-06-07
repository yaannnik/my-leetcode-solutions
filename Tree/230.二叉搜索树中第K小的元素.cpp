#include "TreeNode.h"
#include <stack>
using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        stack<TreeNode*> st;
        while(!st.empty() || root) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            i++;
            root = st.top();
            st.pop();
            if(i == k) {
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }
};
