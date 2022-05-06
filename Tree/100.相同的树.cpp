#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }

    bool dfs(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(p && q && p->val == q->val) {
            return (dfs(p->left, q->left) && dfs(p->right, q->right));
        }
        return false;
    }
};
