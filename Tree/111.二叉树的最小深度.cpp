#include "TreeNode.h"
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }

        queue<pair<TreeNode*, int>> qu;
        qu.emplace(root, 1);

        while(!qu.empty()) {
            TreeNode* node = qu.front().first;
            int depth = qu.front().second;
            qu.pop();

            if(!node->left && !node->right) {
                return depth;
            }
            if(node->left) {
                qu.emplace(node->left, depth + 1);
            }
            if(node->right) {
                qu.emplace(node->right, depth + 1);
            }
        }
        return 0;
    }
};
