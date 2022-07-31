#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for(int i = 0; i < n; i++) {
            parent.emplace_back(i);
        }
        cnt = n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    merge(i, j);
                }
            }
        }
        return cnt;
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
            cnt--;
            if(px < py) {
                parent[py] = px;
            } else {
                parent[px] = py;
            }
        }
    }

    int cnt;
    vector<int> parent;
};
