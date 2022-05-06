#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) {
            return {newInterval};
        }
        vector<vector<int>> res;
        int left = newInterval[0], right = newInterval[1];
        int stopOverlap = -1;

        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][1] < left) {
                res.emplace_back(intervals[i]);
                continue;
            } else if(intervals[i][0] <= right) {
                left = newInterval[0];
                right = newInterval[1];
                newInterval[0] = min(intervals[i][0], left);
                newInterval[1] = max(intervals[i][1], right);
            } else {
                stopOverlap = i;
                break;
            }
        }

        res.emplace_back(newInterval);
        
        if(stopOverlap >= 0) {
            for(int i = stopOverlap; i < intervals.size(); i++) {
                res.emplace_back(intervals[i]);
            }
        }
        

        return res;
    }
};
