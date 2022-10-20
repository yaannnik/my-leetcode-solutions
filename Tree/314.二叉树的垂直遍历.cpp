#include "TreeNode.h"
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        int minCol = 0, maxCol = 0;
        unordered_map<int, vector<int>> col2nodes;
        queue<pair<TreeNode*, int>> qu; // node, col
        qu.emplace(root, 0);
        while(!qu.empty()) {
            auto [node, col] = qu.front();
            qu.pop();
            col2nodes[col].emplace_back(node->val);
            if(node->left) {
                minCol = min(minCol, col - 1);
                qu.emplace(node->left, col - 1);
            }
            if(node->right) {
                maxCol = max(maxCol, col + 1);
                qu.emplace(node->right, col + 1);
            }
        }

        // cout << "here" << endl;
        vector<vector<int>> res;
        for(int col = minCol; col <= maxCol; col++) {
            res.emplace_back(col2nodes[col]);
        }
        return res;
    }
};
