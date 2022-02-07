#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, set<pair<int,int>>> adjacant;
        for(const auto& edge : edges) {
            int f = edge[0], t = edge[1], w = edge[2];
            adjacant[f].insert({t, w});
            adjacant[t].insert({f, w});
        }
        pair<int, int> res(INT_MAX, 0); // res的first为最小城市数，second为城市编号
        // 进行dijkstra算法，求源点s出发的最短路径
        for(int s = 0; s < n; s++) {
            vector<int> dist(n, INT_MAX);
            dist[s] = 0; // 自己到自己的距离设为0
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu; // 小根堆
            qu.push({0, s});
            while(!qu.empty()) {
                auto p = qu.top();
                qu.pop();
                int v = p.second;
                if(dist[v] < p.first) {
                    continue;
                }
                for(const auto& edge : adjacant[v]) {
                    if(dist[edge.first] > dist[v] + edge.second) {
                        dist[edge.first] = dist[v] + edge.second;
                        qu.push({dist[edge.first], edge.first});
                    }
                }
            }
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(dist[i] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= res.first) {
                res.first = cnt;
                res.second = s;
            }
        }
        return res.second;
    }
};
