#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1 = inorder(root1), list2 = inorder(root2), res;
        int i = 0, j = 0;
        while(i < list1.size() && j < list2.size()) {
            if(list1[i] <= list2[j]) {
                res.emplace_back(list1[i]);
                i++;
            } else {
                res.emplace_back(list2[j]);
                j++;
            }
        }
        while(i < list1.size()) {
            res.emplace_back(list1[i]);
            i++;
        }
        while(j < list2.size()) {
            res.emplace_back(list2[j]);
            j++;
        }
        return res;
    }

    vector<int> inorder(TreeNode* root) {
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
