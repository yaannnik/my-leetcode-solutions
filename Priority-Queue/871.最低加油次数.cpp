#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        return a < b;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size(), res = 0;
        int i = 0;
        priority_queue<int, vector<int>, cmp> pq;
        while(startFuel < target) {
            while(i < n && startFuel >= stations[i][0]) {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) {
                return -1;
            }
            startFuel += pq.top(); // 从之前的加油站中挑出最大的加油
            pq.pop();
            res++;
        }
        return res;
    }
};
