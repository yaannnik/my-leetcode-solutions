#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

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
