#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
        vector<int> res;
        for(auto& edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            if(find(x) == find(y)) {
                res = edge;
            } else {
                merge(x, y);
            }
        }
        return res;
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py) {
            if(px < py) {
                parent[py] = px;
            } else {
                parent[px] = py;
            }
        }
    }

    vector<int> parent;

};
