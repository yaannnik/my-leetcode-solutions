#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [&](vector<int>& v1, vector<int>& v2){return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];});
        int left = intervals[0][0], right = intervals[0][1];
        vector<vector<int>> res;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= right) {
                left = min(left, intervals[i][0]);
                right = max(right, intervals[i][1]);
            } else {
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};