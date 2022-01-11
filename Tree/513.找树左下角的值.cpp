#include<vector>
#include<queue>
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) {
            return -1;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        vector<int> tmp;
        while(!qu.empty()) {
            tmp.clear();
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
        }
        return tmp.front();
    }
};
