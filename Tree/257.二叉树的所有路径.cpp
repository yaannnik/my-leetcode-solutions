#include "TreeNode.h"
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) {
            return res;
        }
        string str = "";
        dfs(root, str);
        return res;
    }

    void dfs(TreeNode* node, string str) {
        if(!node->left && !node->right) {
            if(str == "") {
                str += to_string(node->val);
            } else {
                str += "->";
                str += to_string(node->val);
            }
            res.emplace_back(str);
            return;
        }
        if(str == "") {
            str += to_string(node->val);
        } else {
            str += "->";
            str += to_string(node->val);
        }
        if(node->left) {
            dfs(node->left, str);
        }
        if(node->right) {
            dfs(node->right, str);
        }

        return;
    }
};
