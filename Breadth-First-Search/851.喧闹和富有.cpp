#include <vector>
#include <queue>
#include <set>
using namespace std;

class BFS {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> degree(n, 0);
        vector<int> res(n, 0); // store index
        vector<vector<int>> lower(n);
        for(auto& rich : richer) {
            degree[rich[1]]++; // how many people are richer than rich[1]
            lower[rich[0]].emplace_back(rich[1]); // people who are richer than rich[0]
        }
        queue<int> qu;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 0) {
                qu.push(i);
            }
            res[i] = i;
        }
        while(!qu.empty()) {
            int top = qu.front();
            qu.pop();
            for(int& p : lower[top]) {
                if(quiet[res[top]] < quiet[res[p]]) {
                    res[p] = res[top];
                }
                degree[p]--;
                if(degree[p] == 0) {
                    qu.push(p);
                }
            }
        }
        return res;
    }
};

class DFS {
public:
    vector<int> res;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        res = vector<int>(n, -1);
        vector<set<int>> higher(n);
        for(auto& rich : richer) {
            higher[rich[1]].insert(rich[0]);
        }
        for(int i = 0; i < n; i++) {
            dfs(i, higher, quiet);
        }
        return res;
    }

    void dfs(int x, vector<set<int>>& higher, vector<int>& quiet) {
        if (res[x] != -1) {
            return;
        }
        res[x] = x;
        for (const int& y : higher[x]) {
            dfs(y, higher, quiet);
            if (quiet[res[y]] < quiet[res[x]]) {
                res[x] = res[y];
            }
        }
    }
};