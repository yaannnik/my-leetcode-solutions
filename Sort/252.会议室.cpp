#include <vector>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for(int i = 1; i < intervals.size(); i++) {
            if(isOverlap(intervals[i-1], intervals[i])){
                return false;
            }
        }
        return true;
    }

    bool isOverlap(vector<int>& interval1, vector<int>& interval2) {
        return !((interval1[0] >= interval2[1]) || interval1[1] <= interval2[0]);
    }
};
