#include <set>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<set<int>> next(n + 1);
        vector<int> deg(n + 1);
        for(auto& r : relations) {
            deg[r[1]]++;
            next[r[0]].insert(r[1]);
        }
        queue<int> qu;
        for(int i = 1; i <= n; i++) {
            if(deg[i] == 0) {
                qu.push(i);
            }
        }
        if(qu.empty()) {
            return -1;
        }
        int level = 0, cnt = 0;
        while(!qu.empty()) {
            int m = qu.size();
            level++;
            for(int i = 0; i < m; i++) {
                int top = qu.front();
                qu.pop();
                cnt++;
                for(const int& num : next[top]) {
                    deg[num]--;
                    if(deg[num] == 0) {
                        qu.push(num);
                    }
                }
            }
        }
        return cnt == n ? level : -1;
    }
};
