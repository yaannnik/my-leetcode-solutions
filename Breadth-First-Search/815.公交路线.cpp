#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) {
            return 0;
        }
        int n = routes.size();
        unordered_map<int, vector<int>> connection(n); // site -> route
        vector<vector<bool>> mat(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            for(int& site : routes[i]) {
                /**
                 * 先在i，j之间置true，再添加进数组，防止出现同一线路自己联通的问题
                 */
                for(int& j : connection[site]) {
                    mat[i][j] = mat[j][i] = true;
                }
                connection[site].emplace_back(i); // build connection on the same route
            }
        }

        vector<int> dis(n, INT_MAX);
        queue<int> qu;
        for(int& i : connection[source]) {
            dis[i] = 1;
            qu.push(i);
        }
        while(!qu.empty()) {
            int x = qu.front();
            qu.pop();
            for(int y = 0; y < n; y++) {
                if(mat[x][y] && dis[y] == INT_MAX) {
                    dis[y] = dis[x] + 1;
                    qu.push(y);
                }
            }
        }
        int res = INT_MAX;
        for(int& i : connection[target]) {
            if(dis[i] < res) {
                res = dis[i];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
