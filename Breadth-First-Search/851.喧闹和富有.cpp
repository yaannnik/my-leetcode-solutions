#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> degree(n, 0);
        vector<int> res(n, 0); // store index
        vector<vector<int>> higher(n);
        vector<vector<int>> lower(n);
        for(auto& rich : richer) {
            degree[rich[1]]++; // how many people are richer than rich[1]
            higher[rich[1]].emplace_back(rich[0]); // people who are richer than rich[0]
            lower[rich[0]].emplace_back(rich[1]); // people who are poorer than rich[1]
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
            if(!higher[top].empty()) {
                for(int& i : higher[top]) {
                    // 所有比top富有的人和top自己中quiet的最小值
                    if(quiet[res[i]] < quiet[res[top]]) {
                        res[top] = res[i];
                    }
                }
            }
            for(auto& l : lower[top]) {
                degree[l]--;
                if(degree[l] == 0) {
                    qu.push(l);
                }
            }
        }
        return res;
    }
};
