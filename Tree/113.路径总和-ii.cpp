#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return {};
        }
        vector<int> path;
        dfs(root, 0, targetSum, path);
        return res;
    }

    void dfs(TreeNode* node, int tempSum, int targetSum, vector<int> path) {
        if(!node->left && !node->right) {
            if(tempSum + node->val == targetSum) {
                path.push_back(node->val);
                res.push_back(path);
                return;
            } else {
                return;
            }
        }
        path.push_back(node->val);
        if(node->left) {
            dfs(node->left, tempSum + node->val, targetSum, path);
        }
        if(node->right) {
            dfs(node->right, tempSum + node->val, targetSum, path);
        }
    }
};
