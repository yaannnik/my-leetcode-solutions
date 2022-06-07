#include "TreeNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> pre, post;
    vector<int> preorder, postorder;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.empty() || postorder.empty()) {
            return nullptr;
        }

        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            pre[preorder[i]] = i;
            post[postorder[i]] = i;
        }
        this->preorder = preorder;
        this->postorder = postorder;

        TreeNode* root = helper(0, n - 1, 0, n - 1);
        return root;
    }

    TreeNode* helper(int pre_left, int pre_right, int post_left, int post_right) {
        // cout << pre_left << " " << pre_right << " " << post_left << " " << post_right << endl;
        if(pre_left > pre_right || post_left > post_right) {
            return nullptr;
        }
        if(pre_left == pre_right || post_left == post_right) {
            return new TreeNode(preorder[pre_left]);
        }
        TreeNode* root = new TreeNode(preorder[pre_left]);

        int left_root = preorder[pre_left + 1];
        int left_length = post[left_root] - post_left + 1;
        int right_length = (pre_right - pre_left + 1) - left_length;

        // pre[1: left_length], post[0: left_length - 1]
        if(left_length > 0) {
            int left_pre_left = pre_left + 1, left_pre_right = pre_left + left_length;
            int left_post_left = post_left, left_post_right = post_left + (left_length - 1);
            root->left = helper(left_pre_left, left_pre_right, left_post_left, left_post_right);
        } else {
            root->left = nullptr;
        }

        // pre[left_length + 1: -1], post[left_length, -2]
        if(right_length > 0) {
            int right_pre_left = pre_left + left_length + 1, right_pre_right = pre_right;
            int right_post_left = post_left + (left_length - 1) + 1, right_post_right = post_right - 1;
            root->right = helper(right_pre_left, right_pre_right, right_post_left, right_post_right);
        } else {
            root->right = nullptr;
        }

        return root;
    }
};
