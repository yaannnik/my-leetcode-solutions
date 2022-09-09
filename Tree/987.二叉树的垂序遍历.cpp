#include "TreeNode.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        dfs(root, 0, 0);
        vector<int> colVec(cols.begin(), cols.end());
        sort(colVec.begin(), colVec.end());
        vector<vector<int>> res;
        for(int& col : colVec) {
            vector<int> tmp;
            sort(col2nums[col].begin(), col2nums[col].end(), [&](pair<int, int>& a, pair<int, int>& b) {
                return a.first == b.first ? a.second < b.second : a.first < b.first;
            });
            for(auto& [row, num] : col2nums[col]) {
                tmp.emplace_back(num);
            }
            res.emplace_back(tmp);
        }
        return res;
    }

    void dfs(TreeNode* root, int row, int col) {
        cols.insert(col);
        col2nums[col].emplace_back(row, root->val);
        if(root->left) {
            dfs(root->left, row + 1, col - 1);
        }
        if(root->right) {
            dfs(root->right, row + 1, col + 1);
        }
    }

    unordered_map<int, vector<pair<int, int>>> col2nums;
    unordered_set<int> cols;
};
