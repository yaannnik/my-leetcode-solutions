#include <vector>
#include <queue>
using namespace std;

/*
 * Idea: 将每个点和其相邻的点比较。未染色的点染上其他颜色。
 * 如果相邻点中有染上和自己一样的颜色的，则不是二分图。
 */

class Solution {
public:
    const int none = 0;
    const int red = 1;
    const int green = 2;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, none);
        for(int i = 0; i < n; i++) {
            if(colors[i] == none) {
                queue<int> qu;
                qu.emplace(i);
                colors[i] = red;
                while(!qu.empty()) {
                    int p = qu.front();
                    qu.pop();
                    int oppo = colors[p] % 2 + 1;
                    for(int& j : graph[p]) {
                        if(colors[j] != none && colors[j] == colors[p]) {
                            return false;
                        }
                        if(colors[j] == none) {
                            colors[j] = oppo;
                            qu.emplace(j);
                        }
                    }
                }
            }
        }
        return true;
    }
};
