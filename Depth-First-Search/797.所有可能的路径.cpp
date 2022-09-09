#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        int n = graph.size();
        dfs(0, graph, path, n);
        return res;
    }

    void dfs(int pos, vector<vector<int>>& graph, vector<int> path, int n) {
        if(pos == n - 1) {
            res.emplace_back(path);
        }
        for(int& next : graph[pos]) {
            vector<int> path_ = path;
            path_.emplace_back(next);
            dfs(next, graph, path_, n);
        }
    }
};
