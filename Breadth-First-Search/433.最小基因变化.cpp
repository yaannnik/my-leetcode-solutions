#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<char> slices = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        int steps = 0;
        unordered_set<string> bank_(bank.begin(), bank.end());
        int m = start.size(), n = end.size();
        if(!bank_.count(end) || m != n) {
            return -1;
        }
        queue<string> qu;
        qu.push(start);
        while(!qu.empty()) {
            int l = qu.size();
            for(int k = 0; k < l; k++) {
                string front = qu.front();
                qu.pop();
                for(int i = 0; i < n; i++) {
                    for(char& ch : slices) {
                        if(front[i] == ch) {
                            continue;
                        }
                        string tmp = front;
                        tmp[i] = ch;
                        if(tmp == end) {
                            return steps + 1;
                        }
                        if(bank_.count(tmp)) {
                            qu.push(tmp);
                            bank_.erase(tmp);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
