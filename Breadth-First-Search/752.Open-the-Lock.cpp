#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for(string& str : deadends) {
            dead.insert(str);
        }

        if(dead.count(target) || dead.count("0000")) {
            return -1;
        }

        if(target == "0000") {
            return 0;
        }

        unordered_map<char, vector<char>> adj;
        adj['0'] = {'9', '1'};
        adj['1'] = {'0', '2'};
        adj['2'] = {'1', '3'};
        adj['3'] = {'2', '4'};
        adj['4'] = {'3', '5'};
        adj['5'] = {'4', '6'};
        adj['6'] = {'5', '7'};
        adj['7'] = {'6', '8'};
        adj['8'] = {'7', '9'};
        adj['9'] = {'8', '0'};

        queue<string> qu;
        qu.emplace("0000");
        vector<int> visited(10000, 0);
        int step = 0;
        while(!qu.empty()) {
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                string str = qu.front();
                qu.pop();
                for(int j = 0; j < 4; j++) {
                    string tmp = str;
                    tmp[j] = adj[str[j]][0];
                    int num = stoi(tmp);
                    if(!dead.count(tmp) && visited[num] == 0) {
                        if(tmp == target) {
                            return step + 1;
                        } else {
                            qu.emplace(tmp);
                            visited[num] = 1;
                        }
                    }

                    tmp[j] = adj[str[j]][1];
                    num = stoi(tmp);
                    if(!dead.count(tmp) && visited[num] == 0) {
                        if(tmp == target) {
                            return step + 1;
                        } else {
                            qu.emplace(tmp);
                            visited[num] = 1;
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
