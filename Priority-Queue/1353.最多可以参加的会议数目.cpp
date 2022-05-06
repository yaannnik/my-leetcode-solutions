#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if(events.empty()) {
            return 0;
        }
        sort(events.begin(), events.end(), cmp);
        int n = events.size(), res = 0, day = 1;
        int i = 0;
        priority_queue<int> qu;
        while(i < n || !qu.empty()) {
            while(i < n && events[i][0] == day) {
                qu.emplace(-events[i][1]);
                i++;
            }
            while(!qu.empty() && qu.top() > -day) {
                qu.pop();
            }
            if(!qu.empty()) {
                qu.pop();
                res++;
            }
            day++;
        }
        return res;
    }
    bool static cmp(vector<int>& e1, vector<int>& e2) {
        return  e1[0] < e2[0];
    }
};
// @lc code=end

