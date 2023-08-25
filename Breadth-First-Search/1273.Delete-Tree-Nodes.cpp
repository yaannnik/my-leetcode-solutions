#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<int> degree(nodes, 0);
        vector<int> sum(nodes, 0);
        vector<unordered_set<int>> sons(nodes);

        for(int i = 0; i < parent.size(); i++) {
            if(parent[i] == -1) {
                continue;
            }
            sons[parent[i]].insert(i);
            degree[parent[i]]++;
        }

        queue<int> qu;
        for(int i = 0; i < nodes; i++) {
            if(degree[i] == 0) {
                qu.push(i);
            }
            sum[i] = value[i];
        }

        int res = 0;
        while(!qu.empty()) {
            int top = qu.front();
            qu.pop();
            if(top == 0) {
                if(sum[top] == 0) {
                    return 0;
                } else {
                    break;
                }
            }
            if(sum[top] == 0) {
                res += countSubtree(top, sons);
                sons[parent[top]].erase(top);
            }
            sum[parent[top]] += sum[top];
            degree[parent[top]]--;
            if(degree[parent[top]] == 0) {
                qu.push(parent[top]);
            }
        }
        return nodes - res;
    }

    int countSubtree(int node, vector<unordered_set<int>>& sons) {
        if(sons[node].empty()) {
            return 1;
        }
        int res = 1;
        for(const int& son : sons[node]) {
            res += countSubtree(son, sons);
        }
        return res;
    }
};
