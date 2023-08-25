#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int end = 0, n = arr.size();
        if(arr[start] == 0) {
            return true;
        }
        queue<int> qu;
        vector<bool> visited(n, false);
        qu.push(start);
        while(!qu.empty()) {
            int pos = qu.front();
            qu.pop();
            if(arr[pos] == 0) {
                return true;
            }
            visited[pos] = true;
            if(pos + arr[pos] < n && !visited[pos + arr[pos]]) {
                qu.push(pos + arr[pos]);
            }
            if(pos - arr[pos] >= 0 && !visited[pos - arr[pos]]) {
                qu.push(pos - arr[pos]);
            }
        }
        return false;
    }
};
