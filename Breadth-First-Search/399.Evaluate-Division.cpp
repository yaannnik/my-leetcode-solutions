#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = equations.size();
        for(int i = 0; i < n; i++) {
            vector<string> ops = equations[i];
            double value = values[i];
            string a = ops[0], b = ops[1];
            mp[a].push_back({b, value});
            mp[b].push_back({a, 1.0/value});
        }

        vector<double> res;
        for(auto query : queries) {
            res.emplace_back(calculate(query[0], query[1]));
        }
        return res;
    }

    double calculate(string start, string end) {
        if(!mp.count(start) || !mp.count(end)) {
            return -1.0;
        }
        if(start == end) {
            return 1.0;
        }
        unordered_set<string> visited;
        queue<pair<string, double>> qu;

        qu.push({start, 1.0});
        visited.insert(start);

        while(!qu.empty()) {
            auto [tmp, path] = qu.front();
            qu.pop();
            for(auto [num, weight] : mp[tmp]) {
                if(num == end) {
                    return path * weight;
                }
                if(!visited.count(num)) {
                    visited.insert(num);
                    qu.push({num, path * weight});
                }
            }
        }
        return -1.0;
    }

    unordered_map<string, vector<pair<string, double>>> mp;
};
