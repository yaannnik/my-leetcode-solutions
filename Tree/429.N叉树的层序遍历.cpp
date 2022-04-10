#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) {
            return {};
        }

        queue<Node*> qu;
        qu.push(root);
        vector<vector<int>> res;

        while(!qu.empty()) {
            int l = qu.size();
            vector<int> tmp;
            for(int i = 0; i < l; i++) {
                Node* node = qu.front();
                qu.pop();
                tmp.emplace_back(node->val);
                for(Node* child : node->children) {
                    qu.push(child);
                }
            }
            res.emplace_back(tmp);
        }

        return res;
    }
};
