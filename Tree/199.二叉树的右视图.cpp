#include "TreeNode.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> res;
        if(!root){
            return res;
        }
        TreeNode* layerLast = root;
        TreeNode* newLayerLast = nullptr;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* node = qu.front();
            qu.pop();
            if(node->left){
                qu.push(node->left);
                newLayerLast = node->left;
            }
            if(node->right){
                qu.push(node->right);
                newLayerLast = node->right;
            }
            if(node == layerLast){
                res.push_back(node->val);
                layerLast = newLayerLast;
            }
        }
        return res;
    }
};
