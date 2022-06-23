#include <vector>
#include <string>
#include <stack>
#include <utility>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<vector<int>> mp(n);
        stack<pair<int,int>> st;

        for(string& log : logs) {
            vector<int> tmp = decomposeLog(log);
            int id = tmp[0]; // cout << id << endl;
            int op = tmp[1]; // cout << op << endl;
            int ts = tmp[2]; // cout << ts << endl;

            if(op == 1) {
                if(!st.empty()) {
                    auto [id_, ts_] = st.top();
                    mp[id_].emplace_back(ts - 1);
                }
                mp[id].emplace_back(ts);
                st.push({id, ts});
            } else {
                mp[id].emplace_back(ts);
                st.pop();
                if(!st.empty()) {
                    auto [id_, ts_] = st.top();
                    mp[id_].emplace_back(ts + 1);
                }
            }
        }
        // cout << "here" << endl;
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            vector<int> tmp = mp[i];
            int t = 0;
            for(int j = 1; j < tmp.size(); j += 2) {
                t += (tmp[j] - tmp[j-1] + 1);
            }
            res[i] = t;
        }

        return res;
    }

    vector<int> decomposeLog(string log) {
        stringstream ss(log);
        string slice = "";
        vector<int> res;
        while(getline(ss, slice, ':')) {
            if(slice == "start") {
                res.emplace_back(1);
            } else if(slice == "end") {
                res.emplace_back(-1);
            } else {
                res.emplace_back(stoi(slice));
            }
        }
        return res;
    }
};
