#include<vector>
using namespace std;

class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        cnt = 0;
        int m = grid.size(), n = grid[0].size();
        rank = vector<int>((m+1) * (n+1), 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    parent.emplace_back(i * n + j);
                    cnt++;
                } else {
                    parent.emplace_back(-1);
                }
            }
        }
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rooty] += 1;
            cnt--;
        }
    }

    vector<int> parent;
    vector<int> rank;
    int cnt;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        UnionFind uf(grid);
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i - 1 >= 0 && grid[i-1][j] == '1') uf.merge(i*n+j, (i-1)*n+j);
                    if (i + 1 < m && grid[i+1][j] == '1') uf.merge(i*n+j, (i+1)*n+j);
                    if (j - 1 >= 0 && grid[i][j-1] == '1') uf.merge(i*n+j, i*n+(j-1));
                    if (j + 1 < n && grid[i][j+1] == '1') uf.merge(i*n+j, i*n+(j+1));
                }
            }
        }
        return uf.cnt;
    }
};
