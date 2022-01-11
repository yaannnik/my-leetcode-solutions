#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        //构造入度和边
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
        int cnt = 0;
        while(!qu.empty()) {
            //每次将当前入度为0的点弹出
            int front = qu.front();
            qu.pop();
            cnt++;
            for(int i = 0; i < edges[front].size(); i++) {
                int target = edges[front][i];
                in[target]--;
                if(in[target] == 0) {
                    qu.push(target);
                }
            }
        }
        return cnt == numCourses;
    }
};
