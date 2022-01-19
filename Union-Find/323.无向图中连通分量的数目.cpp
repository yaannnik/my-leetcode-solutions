#include <vector>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n, -1);
        cnt = n;
        for(auto& e : edges) {
            if(parent[e[0]] == -1) {
                parent[e[0]] = e[0];
            }
            if(parent[e[1]] == -1) {
                parent[e[1]] = e[1];
            }
            merge(e[0], e[1]);
        }
        return cnt;
    }

    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        if(find(x) != find(y)) {
            cnt--;
        }
        parent[find(x)] = find(y);
    }

    vector<int> parent;
    int cnt;
};
