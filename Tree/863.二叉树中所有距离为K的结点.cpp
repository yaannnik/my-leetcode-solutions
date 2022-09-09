#include "TreeNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent[root->val] = nullptr;
        findParent(root);
        dfs(target, nullptr, 0, k);
        return res;
    }

    void findParent(TreeNode* node) {
        if(node->left) {
            parent[node->left->val] = node;
            findParent(node->left);
        }
        if(node->right) {
            parent[node->right->val] = node;
            findParent(node->right);
        }
    }

    void dfs(TreeNode* node, TreeNode* from, int depth, int k) {
        if(depth == k) {
            res.emplace_back(node->val);
            return;
        }
        if(node->left && node->left != from) {
            dfs(node->left, node, depth + 1, k);
        }
        if(node->right && node->right != from) {
            dfs(node->right, node, depth + 1, k);
        }
        if(parent[node->val] && parent[node->val] != from) {
            dfs(parent[node->val], node, depth + 1, k);
        }
    }

    unordered_map<int, TreeNode*> parent;
    vector<int> res;
};
