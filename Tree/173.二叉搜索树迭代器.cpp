#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        ptr = -1;
        this->root = root;
        while(this->root || !st.empty()) {
            while(this->root) {
                st.push(this->root);
                this->root = this->root->left;
            }
            this->root = st.top();
            st.pop();
            vals.emplace_back(this->root->val);
            this->root = this->root->right;
        }
    }

    int next() {
        ptr++;
        return ptr < vals.size() ? vals[ptr] : -1;
    }

    bool hasNext() {
        return ptr + 1 < vals.size();
    }

    TreeNode* root;
    stack<TreeNode*> st;
    vector<int> vals;
    int ptr;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
