#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int m = row.size(), n = m / 2;
        cnt = n;
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
        for(int i = 0; i < m; i += 2) {
            // group id = row[i] / 2;
            // 所有坐错位置的row[i]会被merge进一个集合
            merge(row[i] / 2, row[i + 1] / 2);
        }

        // 假设一共n对情侣，k对坐错了，那么并查集内一共会有cnt = (n - k) + 1个集合
        int k = n - cnt + 1;
        return k - 1;
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
