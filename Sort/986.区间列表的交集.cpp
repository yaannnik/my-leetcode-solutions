#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int idx1 = 0, idx2 = 0;
        int m = firstList.size(), n = secondList.size();
        vector<vector<int>> res;

        while(idx1 < m && idx2 < n) {
            vector<int> &interval1 = firstList[idx1], &interval2 = secondList[idx2];
            if(hasOverlap(interval1, interval2)) {
                res.push_back({max(interval1[0], interval2[0]), min(interval1[1], interval2[1])});
            }
            if(interval1[1] < interval2[1]) {
                idx1++;
            } else if(interval1[1] > interval2[1]) {
                idx2++;
            } else {
                idx1++;
                idx2++;
            }
        }

        return res;
    }

    bool hasOverlap(vector<int>& interval1, vector<int>& interval2) {
        if(interval1[1] < interval2[0] || interval2[1] < interval1[0]) {
            return false;
        }
        return true;
    }
};
