#include "TreeNode.h"
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) {
            return res;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()) {
            int l = qu.size();
            res.push_back(INT_MIN);
            for(int i = 0; i < l; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                res.back() = max(res.back(), node->val);
                if(node->left) {
                    qu.push(node->left);
                }
                if(node->right) {
                    qu.push(node->right);
                }
            }
        }
        return res;
    }
};
