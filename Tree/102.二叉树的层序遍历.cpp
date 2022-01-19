#include <vector>
#include <queue>
using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> res;
        while(!qu.empty()) {
            vector<int> tmp;
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                TreeNode* front = qu.front();
                qu.pop();
                tmp.emplace_back(front->val);
                if(front->left) {
                    qu.push(front->left);
                }
                if(front->right) {
                    qu.push(front->right);
                }
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
