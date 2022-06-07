#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return nullptr;
        }
        if(key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if(!root->left || !root->right) {
                root = root->left ? root->left : root->right;
            } else {
                TreeNode* cur = root->right;
                while(cur->left) {
                    cur = cur->left;
                }
                root->val = cur->val;
                root->right = deleteNode(root->right, cur->val);
            }
        }
        return root;
    }
};
