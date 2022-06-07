#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(find(p, q)) {
            return p;
        }
        else if(find(q, p)) {
            return q;
        }
        else{
            if((find(root->left, p) && find(root->right, q)) || (find(root->left, q) && find(root->right, p))) {
                return root;
            }
            else if(find(root->left, p) && find(root->left, q)){
                return lowestCommonAncestor(root->left, p, q);
            }
            else{
                return lowestCommonAncestor(root->right, p, q);
            }
        }
        return nullptr;
    }

    bool find(TreeNode* root, TreeNode* target) {
        if(root == nullptr) {
            return false;
        }
        if(root == target) {
            return true;
        }
        return find(root->left, target) || find(root->right, target);
    }
};
