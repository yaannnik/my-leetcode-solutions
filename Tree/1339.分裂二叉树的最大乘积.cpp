#include "TreeNode.h"
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class OneDFS {
public:
    int maxProduct(TreeNode* root) {
        if(!root) {
            return 0;
        }
        long sum = treeSum(root);
        long res = 0;
        for(int& num : allSums) {
            res = max(res, num * (sum - num));
        }
        return res % mod;
    }

    int treeSum(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int leftSum = treeSum(root->left);
        int rightSum = treeSum(root->right);

        allSums.emplace_back(leftSum + rightSum + root->val);
        return leftSum + rightSum + root->val;
    }


    vector<int> allSums;
    int mod = 1e9+7;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class TwoDFS {
public:
    int maxProduct(TreeNode* root) {
        if(!root) {
            return 0;
        }
        sum = treeSum(root);
        findMaxProduct(root);
        return res % mod;
    }

    int treeSum(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int leftSum = treeSum(root->left);
        int rightSum = treeSum(root->right);

        return leftSum + rightSum + root->val;
    }

    int findMaxProduct(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int leftSum = findMaxProduct(root->left);
        int rightSum = findMaxProduct(root->right);
        int tmpSum = leftSum + rightSum + root->val;

        long product = tmpSum * (sum - tmpSum);
        res = max(res, product);

        return tmpSum;
    }


    long sum = 0;
    long res = 0;
    int mod = 1e9+7;
};
