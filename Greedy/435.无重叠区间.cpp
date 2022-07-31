#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int right = intervals[0][1];
        int ans = 1, n = intervals.size();
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= right) {
                right = intervals[i][1];
                ans++;
            }
        }
        return n - ans;
    }

    static bool cmp(vector<int>& interval1, vector<int>& interval2) {
        return interval1[1] < interval2[1];
    }
};
