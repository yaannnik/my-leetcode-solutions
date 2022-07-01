#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int,int>>> graph(n);
        for(auto time : times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];
            graph[u - 1].emplace_back(v - 1, t);
        }
        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k - 1);
        while(!pq.empty()) {
            auto [time, x] = pq.top();
            pq.pop();
            if(time > dist[x]) {
                continue;
            }
            for (auto& e : graph[x]) {
                int y = e.first, d = dist[x] + e.second;
                if (d < dist[y]) {
                    dist[y] = d;
                    pq.emplace(d, y);
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};
