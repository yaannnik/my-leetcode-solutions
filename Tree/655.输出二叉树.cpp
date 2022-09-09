#include <vector>
#include <string>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) {
            return {};
        }
        height = maxHeight(root) - 1;
        int m = height + 1, n = (1 << (height + 1)) - 1;
        res = vector<vector<string>>(m, vector<string>(n, ""));
        dfs(root, 0, (n - 1)/2);
        return res;
    }

    void dfs(TreeNode* node, int r, int c) {
        // if(!node) {
        //     res[r][c] = "";
        //     return;
        // }
        res[r][c] = to_string(node->val);
        // cout << height << " " << r << " " << c << endl;
        if(node->left) {
            dfs(node->left, r + 1, c - (1 << (height - r - 1)));
        }
        if(node->right) {
            dfs(node->right, r + 1, c + (1 << (height - r - 1)));
        }

    }

    int maxHeight(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }

    int height;
    vector<vector<string>> res;
};
