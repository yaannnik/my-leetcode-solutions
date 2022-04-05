#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for(auto& edge : edges) {
            int a = edge[0], b = edge[1];
            deg[a]++;
            deg[b]++;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        unordered_set<int> st;
        queue<int> qu;
        for(int i = 0; i < n; i++) {
            st.insert(i);
            if(deg[i] == 1) {
                qu.push(i);
            }
        }
        while(st.size() > 2 && !qu.empty()) {
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                // cout << qu.size() << endl;
                int u = qu.front();
                qu.pop();
                st.erase(u);
                for(int& v : adj[u]) {
                    if(st.count(v)) {
                        deg[v]--;
                        if(deg[v] == 1) {
                            qu.push(v);
                        }
                    }
                }
            }
        }

        vector<int> res;
        for(const int& i : st) {
            res.emplace_back(i);
        }
        return res;
    }
};
