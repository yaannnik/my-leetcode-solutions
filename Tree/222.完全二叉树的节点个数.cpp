#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        while (node->left != nullptr) {
            level++;
            node = node->left;
        }
        if(level == 0) {
            return 1;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low <= high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }

    bool exists(TreeNode* root, int level, int k) {
        int bits = 1 << (level - 1); // 处于第level位
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) {
                node = node->left;
            } else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
};
