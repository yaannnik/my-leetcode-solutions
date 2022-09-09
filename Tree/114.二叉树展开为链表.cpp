#include "TreeNode.h"
using namespace std;

class Traverse {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        // 从上往下，把每个节点的右子树移到左子树最右下角节点右，然后将左子树移到右子树
        while(cur) {
            if(cur->left) {
                TreeNode* tmp = cur->left;
                while(tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = cur->right;

                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};

class Recursive {
public:
    void flatten(TreeNode* root) {
        if(!root) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* node = root;
        while(node->right) {
            node = node->right;
        }
        node->right = right;
    }
};
