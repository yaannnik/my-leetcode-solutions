#include <vector>
using namespace std;

class Solution {
public:
    int res;
    int maximumRequests(int n, vector<vector<int>>& requests) {
        for(int i = 1; i <= requests.size(); i++) {
            vector<int> mp(n, 0);
            dfs(i, 0, 0, mp, requests, n);
        }
        return res;
    }

    void dfs(int k, int cnt, int idx, vector<int>& mp, vector<vector<int>>& requests, int n) {
        if(cnt == k) {
            if(mp == vector<int>(n, 0)) {
                res = max(res, cnt);
            }
            return;
        }
        for(int i = idx; i < requests.size(); i++) {
            int from = requests[i][0], to = requests[i][1];
            mp[from]--;
            mp[to]++;
            dfs(k, cnt + 1, i + 1, mp, requests, n);
            mp[from]++;
            mp[to]--;
        }
    }
};
