#include <string>
#include <queue>
#include <sstream>
#include "TreeNode.h"
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "null,";
        }
        string res = to_string(root->val) + ",";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string> qu;
        while (getline(ss, item, ',')) {
            qu.push(item);
        }
        TreeNode* root = helper(qu);
        return root;
    }

    TreeNode* helper(queue<string>& qu) {
        string front = qu.front();
        qu.pop();
        if(front == "null") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(front));
        root->left = helper(qu);
        root->right = helper(qu);
        return root;
    }
};
