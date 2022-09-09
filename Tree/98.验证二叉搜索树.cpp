#include "TreeNode.h"
#include <numeric>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* node, long long min, long long max) {
        if(!node)
            return true;
        if(node->val <= min || node->val >= max)
            return false;
        return (dfs(node->left, min, node->val) && 
                dfs(node->right, node->val, max));

    }
};

class Traverse {
public:
    bool isValidBST(TreeNode* root) {
        long long prev = (long long)INT_MIN - 1;
        stack<TreeNode*> st;
        while(!st.empty() || root) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            if(root->val <= prev) {
                return false;
            }
            st.pop();
            prev = root->val;
            root = root->right;
        }
        return true;
    }
};

class MorrisTraverse {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) {
            return false;
        }
        long prev = LONG_MIN;
        TreeNode* cur = root;
        bool res = true;
        while(cur) {
            if(cur->left) {
                TreeNode* mostr = cur->left;
                while(mostr->right && mostr->right != cur) {
                    mostr = mostr->right;
                }
                if(mostr->right != cur) {
                    mostr->right = cur;
                    cur = cur->left;
                } else {
                    if(cur->val <= prev) {
                        res = false;
                    } else {
                        prev = cur->val;
                    }
                    mostr->right = nullptr;
                    cur = cur->right;
                }
            } else {
                if(cur->val <= prev) {
                    res = false;
                } else {
                    prev = cur->val;
                }
                cur = cur->right;
            }
        }
        return res;
    }
};
