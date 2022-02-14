#include "TreeNode.h"
#include <map>
using namespace std;

class Solution {
public:
    map<TreeNode*, int> mp;
    int max_depth;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        max_depth = -1;
        depth(root, 1);
        TreeNode* res = find(root);
        return res;
    }

    void depth(TreeNode* node, int d) {
        mp[node] = d;
        max_depth = max(max_depth, d);

        if(node->left) {
            depth(node->left, d + 1);
        }
        if(node->right) {
            depth(node->right, d + 1);
        }
    }

    TreeNode* find(TreeNode* node) {
        if(mp[node] == max_depth) {
            return node;
        }
        TreeNode *L = nullptr, *R = nullptr;
        if(node->left) {
            L = find(node->left);
        }
        if(node->right) {
            R = find(node->right);
        }
        if(L && R) {
            return node;
        } else if(L) {
            return L;
        } else if(R) {
            return R;
        } else {
            return nullptr;
        }
    }

};
