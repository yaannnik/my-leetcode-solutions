#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        return dfs(nums, left, right);
    }

    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if(left <= right) {
            int mid = left + (right - left)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = dfs(nums, left, mid - 1);
            root->right = dfs(nums, mid + 1, right);
            return root;
        } else {
            return nullptr;
        }
        
    }
};
