struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ptr = root;
        if(!root) {
            root = new TreeNode(val);
            return root;
        }
        while(ptr) {
            if(val < ptr->val) {
                if(ptr->left) {
                    ptr = ptr->left;
                } else {
                    ptr->left = new TreeNode(val);
                    ptr = nullptr;
                }
            } else {
                if(ptr->right) {
                    ptr = ptr->right;
                } else {
                    ptr->right = new TreeNode(val);
                    ptr = nullptr;
                }
            }
        }
        delete ptr;
        return root;
    }
};
