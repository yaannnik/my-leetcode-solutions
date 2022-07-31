#include <vector>
#include <queue>
#include <tuple>
#include <numeric>
using namespace std;

struct cmp {
    bool operator()(tuple<int, int, int> t1, tuple<int, int, int> t2) {
        auto [src1, dst1, cost1] = t1;
        auto [src2, dst2, cost2] = t2;
        return cost1 > cost2;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        int n = rows * cols;
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;
        // 建立三元组 [起点， 终点， 权重]（无向）
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int dst = i * cols + j;
                if(i > 0) {
                    int src = (i - 1) * cols + j;
                    int cost = abs(heights[i][j] - heights[i-1][j]);
                    pq.emplace(src, dst, cost);
                }
                if(j > 0) {
                    int src = i * cols + (j - 1);
                    int cost = abs(heights[i][j] - heights[i][j-1]);
                    pq.emplace(src, dst, cost);
                }
            }
        }
        int start = 0, end = n - 1;
        int res = 0;
        // 每次挑选权重最小的边，连接两侧，直到起点终点相连接
        while(!connected(start, end)) {
            auto [src, dst, cost] = pq.top();
            pq.pop();
            merge(src, dst);
            res = cost;
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
        int px = find(x), py = find(y);
        if(px != py) {
            if(px < py) {
                parent[py] = px;
            } else {
                parent[px] = py;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    vector<int> parent;
};
