#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        for(auto& p : prerequisites) {
            in[p[0]]++;
            edges[p[1]].emplace_back(p[0]);
        }
        queue<int> qu;
        for(int i = 0; i < numCourses; i++) {
            if(in[i] == 0) {
                qu.push(i);
            }
        }
        vector<int> res;
        while(!qu.empty()) {
            int front = qu.front();
            qu.pop();
            res.emplace_back(front);
            for(int i = 0; i < edges[front].size(); i++) {
                int target = edges[front][i];
                in[target]--;
                if(in[target] == 0) {
                    qu.push(target);
                }
            }
        }
        if(res.size() != numCourses) {
            return {};
        }
        return res;
    }
};
