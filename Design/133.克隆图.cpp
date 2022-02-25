#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* visited[101] = {nullptr};

    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }

        Node* res = new Node(node->val, vector<Node*> {});
        visited[node->val] = res;
        for(Node* child : node->neighbors) {
            if (!visited[child->val])
                res->neighbors.push_back(cloneGraph(child));
            else
                res->neighbors.push_back(visited[child->val]);
        }
        return res;
    }
};
