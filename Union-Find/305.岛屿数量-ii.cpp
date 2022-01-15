#include<vector>
using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        cnt = 0;
        parent = vector<int>((m+1)*(n+1), -1);
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<int> res;
        for(auto& p : positions) {
            int x = p[0], y = p[1];
            grid[x][y] = 1;
            if(parent[x*n+y] != -1) {
                res.emplace_back(cnt);
                continue;
            }
            cnt++;
            parent[x*n+y] = x*n+y;
            if(x - 1 >= 0 && grid[x-1][y] == 1) merge(x * n + y, (x - 1) * n + y);
            if(x + 1 < m && grid[x+1][y] == 1) merge(x * n + y, (x + 1) * n + y);
            if(y - 1 >= 0 && grid[x][y-1] == 1) merge(x * n + y, x * n + y - 1);
            if(y + 1 < n && grid[x][y+1] == 1) merge(x * n + y, x * n + y + 1);
            res.emplace_back(cnt);
        }
        return res;
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
