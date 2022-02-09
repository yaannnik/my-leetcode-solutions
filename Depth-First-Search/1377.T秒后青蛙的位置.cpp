#include <vector>
#include <set>
#include <queue>
using namespace std;

class DFS {
public:
    double res = 0.0;
    vector<set<int>> children;
    vector<bool> visited;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        children = vector<set<int>>(n + 1);
        visited = vector<bool>(n + 1, false);

        for(auto& edge : edges) {
            int a = edge[0], b = edge[1];
            children[a].insert(b);
            children[b].insert(a);
        }
        visited[1] = true;
        dfs(0, 1.0, 1, target, t);
        return res;
    }

    void dfs(int tick, double p, int vertex, int target, int t) {
        if(tick > t) {
            return;
        }
        if(vertex == target) {
            if(tick == t || (tick < t && countAvaiable(vertex) == 0)) {
                res = p;
                return;
            }
            else {
                return;
            }
        }
        int k = countAvaiable(vertex);
        for(const int& v : children[vertex]) {
            if(!visited[v]) {
                visited[v] = true;
                dfs(tick + 1, p * (1.0 / k), v, target, t);
                visited[v] = false;
            }
        }
    }

    int countAvaiable(int vertex) {
        int cnt = 0;
        for(const int& c : children[vertex]) {
            if(!visited[c]) {
                cnt++;
            }
        }
        return cnt;
    }
};


class BFS {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<set<int>> children(n + 1);
        vector<bool> visited(n + 1, false);

        for(auto& edge : edges) {
            int a = edge[0], b = edge[1];
            children[a].insert(b);
            children[b].insert(a);
        }
        int tick = 0;
        queue<pair<int, double>> qu;
        qu.push({1, 1.0});
        while(!qu.empty()) {
            int m = qu.size();
            for(int i = 0; i < m; i++) {
                int vertex = qu.front().first;
                double p = qu.front().second;
                visited[vertex] = true;
                qu.pop();
                if(vertex == target) {
                    if(t == tick) {
                        return p;
                    } else {
                        if(countAvaiable(vertex, children, visited) == 0) {
                            return p;
                        } else {
                            return 0.0;
                        }
                    }
                }
                int k = countAvaiable(vertex, children, visited);
                for(const int& c : children[vertex]) {
                    if(!visited[c]) {
                        qu.push({c, p * (1.0 / k)});
                    }
                }
            }
            tick++;
            if(tick > t) {
                break;
            }
        }
        return 0.0;
    }

    int countAvaiable(int vertex, vector<set<int>>& children, vector<bool>& visited) {
        int cnt = 0;
        for(const int& c : children[vertex]) {
            if(!visited[c]) {
                cnt++;
            }
        }
        return cnt;
    }
};