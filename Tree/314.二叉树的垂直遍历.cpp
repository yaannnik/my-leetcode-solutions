#include "TreeNode.h"
#include <vector>
#include <utility>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) {
            return res;
        }
        queue<pair<int, TreeNode*>> qu;
        qu.emplace(0, root);
        while(!qu.empty()) {
            auto [col, node] = qu.front();
            qu.pop();

            col2nums[col].emplace_back(node->val);
            uniqueCols.insert(col);

            if(node->left) {
                qu.emplace(col-1, node->left);
            }
            if(node->right) {
                qu.emplace(col+1, node->right);
            }
        }

        vector<int> sortedCols = vector<int>(uniqueCols.begin(), uniqueCols.end());
        sort(sortedCols.begin(), sortedCols.end());

        for(int& col : sortedCols) {
            res.push_back(col2nums[col]);
        }

        return res;
    }

    unordered_map<int, vector<int>> col2nums;
    unordered_set<int> uniqueCols;
};
