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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        queue<TreeNode*> qu;
        qu.push(root);
        int level = 0;
        vector<vector<int>> res;
        while(!qu.empty()) {
            level++;
            deque<int> dq;
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                TreeNode* front = qu.front();
                qu.pop();
                if(level % 2 == 1) {
                    dq.push_back(front->val);
                } else {
                    dq.push_front(front->val);
                }
                if(front->left) {
                    qu.push(front->left);
                }
                if(front->right) {
                    qu.push(front->right);
                }
            }
            res.emplace_back(dq.begin(), dq.end());
        }
        return res;
    }
};