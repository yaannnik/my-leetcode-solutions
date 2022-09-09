#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) {
            return nullptr;
        }
        auto maxIt = max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(*maxIt);
        vector<int> leftVec = vector<int>(nums.begin(), maxIt);
        vector<int> rightVec = vector<int>(maxIt + 1, nums.end());
        root->left = constructMaximumBinaryTree(leftVec);
        root->right = constructMaximumBinaryTree(rightVec);
        return root;
    }
};
