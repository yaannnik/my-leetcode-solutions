#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        cnt = n;
        parent = vector<int>(n, -1);
        iota(parent.begin(), parent.end(), 0);
        for(auto& edge : edges) {
            int a = edge[0], b = edge[1];
            if(!merge(a, b)) {
                return false;
            }
        }
        return cnt == 1;
    }

    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool merge(int x, int y) {
        if(find(x) == find(y)) {
            return false;
        }
        if(find(x) != find(y)) {
            cnt--;
        }
        parent[find(x)] = find(y);
        return true;
    }

    int cnt;
    vector<int> parent;
};
