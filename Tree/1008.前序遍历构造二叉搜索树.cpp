#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = nullptr;
        for(int i = 0; i < preorder.size(); i++) {
            insert(root, preorder[i]);
        }
        return root;
    }

    // 这里要用指针的引用，否则每次传入的root都是没有指向任何地点的空指针
    void insert(TreeNode* &root, int target) {
        if(!root) {
            root = new TreeNode(target);
            return;
        }
        TreeNode* ptr = root;
        while(true) {
            if(target <= ptr->val) {
                if(ptr->left) {
                    ptr = ptr->left;
                } else {
                    ptr->left = new TreeNode(target);
                    return;
                }
            } else {
                if(ptr->right) {
                    ptr = ptr->right;
                } else {
                    ptr->right = new TreeNode(target);
                    // cout << target << endl;
                    return;
                }
            }
        }
    }
};
