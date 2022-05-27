#include "TreeNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> in, post;
    vector<int> inorder, postorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            in[inorder[i]] = i;
            post[postorder[i]] = i;
            this->inorder = inorder;
            this->postorder = postorder;
        }

        TreeNode* root = helper(0, n - 1, 0, n - 1);
        return root;
    }

    TreeNode* helper(int in_left, int in_right, int post_left, int post_right) {
        // cout << in_left << " " << in_right << " " << post_left << " " << post_right << endl;
        if(in_left > in_right || post_left > post_right) {
            return nullptr;
        }
        if(in_left == in_right || post_left == post_right) {
            return new TreeNode(inorder[in_left]);
        }
        TreeNode* root = new TreeNode(postorder[post_right]);
        int in_root = in[postorder[post_right]];
        int left_length = in_root - in_left, right_length = in_right - in_root;

        if(left_length > 0) {
            int left_in_left = in_left, left_in_right = in_left + left_length - 1;
            int left_post_left = post_left, left_post_right = post_left + left_length - 1;
            root->left = helper(left_in_left, left_in_right, left_post_left, left_post_right);
        } else {
            root->left = nullptr;
        }

        if(right_length > 0) {
            int right_in_left = in_root + 1, right_in_right = in_root + right_length;
            int right_post_left = post_right - right_length, right_post_right = post_right - 1;
            root->right = helper(right_in_left, right_in_right, right_post_left, right_post_right);
        } else {
            root->right = nullptr;
        }

        return root;
    }
};
