#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        map<int, set<int>> adj;
        for(auto& p : pairs) {
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
        }
        int root = -1, res = 1, n = adj.size();

        for(auto& [node, neighbours] : adj) {
            if(neighbours.size() == n - 1) {
                // degree为n-1的node作为root
                root = node;
                break;
            }
        }
        if(root == -1) {
            return 0;
        }

        for(auto& [node, neighbours] : adj) {
            if(node == root) {
                continue;
            }

            int selfDegree = neighbours.size();
            int parent = -1;
            int parentDegree = INT_MAX;

            for(auto& neighbour : neighbours) {
                if(adj[neighbour].size() < parentDegree && adj[neighbour].size() >= selfDegree) {
                    // 找到neighbours中degree比自己大的但是最小的作为父节点
                    parent = neighbour;
                    parentDegree = adj[neighbour].size();
                }
            }
            if(parent == -1) {
                return 0;
            }

            for(auto& neighbour : neighbours) {
                if(neighbour == parent) {
                    continue;
                }
                if(!adj[parent].count(neighbour)) {
                    // 自己的neighbour不是parent的neighbour，说明不可能构造出tree
                    return 0;
                }
            }
            if(parentDegree == selfDegree) {
                // 如果满足parent条件的node不止一个，则不止一种方案
                res = 2;
            }
        }
        return res;
    }
};
