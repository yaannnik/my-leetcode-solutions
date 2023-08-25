#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;

/*
 * 对于k个partitions，需要k-1条线连通。
 * 对每个partition的size，只需要size-1条线。
 * 检查每个partition内冗余的线的总数量和是否大于k-1即可
 */
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        groupSize = vector<int>(n, 1);
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
        cnt = n;

        for(auto& connection : connections) {
            int x = connection[0], y = connection[1];
            merge(x, y);
        }

        unordered_map<int, int> index2wires;
        for(auto& connection : connections) {
            int x = connection[0], y = connection[1];
            int root = find(x);
            index2wires[root]++;
        }

        int needed = cnt - 1;
        for(auto [root, wires] : index2wires) {
            int redundant = wires - (groupSize[root] - 1);
            needed -= redundant;
        }

        if(needed <= 0) {
            return cnt - 1;
        } else {
            return -1;
        }
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
                groupSize[px] += groupSize[py];
            } else {
                parent[px] = py;
                groupSize[py] += groupSize[px];
            }
        }
    }

    vector<int> parent;
    vector<int> groupSize;
    int cnt;
};
