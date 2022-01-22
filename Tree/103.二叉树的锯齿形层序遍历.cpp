#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

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