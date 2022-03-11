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
// @lc code=end

