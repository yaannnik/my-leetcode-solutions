#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> qu;
        qu.emplace(root);
        while(!qu.empty()) {
            int l = qu.size();
            int sum_tmp = 0;
            for(int i = 0; i < l; i++) {
                TreeNode* front = qu.front();
                qu.pop();
                sum_tmp += front->val;
                if(front->left) {
                    qu.emplace(front->left);
                }
                if(front->right) {
                    qu.emplace(front->right);
                }
            }
            sum = sum_tmp;
        }
        return sum;
    }
};
