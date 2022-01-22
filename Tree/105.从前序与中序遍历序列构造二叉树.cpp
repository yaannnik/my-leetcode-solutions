#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* root = constructor(preorder, 0, n - 1, inorder, 0, n - 1);
        return root;
    }

    TreeNode* constructor(vector<int>& preorder, int pre_left, int pre_right,
                          vector<int>& inorder, int in_left, int in_right) {
        if(pre_left == pre_right && in_left == in_right) {
            return new TreeNode(preorder[pre_left]);
        }
        TreeNode* root = new TreeNode(preorder[pre_left]);
        int in_root;
        for(int i = in_left; i <= in_right; i++) {
            if(inorder[i] == root->val) {
                in_root = i;
                break;
            }
        }
        int left_len = in_root - in_left;
        int right_len = in_right - in_root;

        if(left_len) {
            root->left = constructor(preorder, pre_left + 1, pre_left + left_len, inorder, in_left, in_root - 1);
        }

        if(right_len) {
            root->right = constructor(preorder, pre_left + left_len + 1, pre_right, inorder, in_root + 1, in_right);
        }


        return root;
    }
};
