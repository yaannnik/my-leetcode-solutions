#include <vector>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        /**
         * 出现在其之前的任一区间 [l_j, r_j)一定满足 l_j < l_i。
         * 因此只要存在一个区间 [l_j, r_j)满足 j < i 且 r_j >= r_i，那么区间 [l_i, r_i)一定会被覆盖。
         * 换句话说，只要出现在 [l_i, r_i)之前的区间的右端点最大值 r_max = max(r_1, r_2, ..., r_{i-1})满足 r_max > r_i，
         * 那么区间 [l_i, r_i)一定会被覆盖；
         *
         * 出现在其之后的任一区间 [l_j, r_j)一定满足 l_j > l_i，因此区间 [l_i, r_i)不可能被任何出现在其之后的区间覆盖。
         */
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
        int ans = n;
        int rmax = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][1] <= rmax) {
                --ans;
            }
            else {
                rmax = max(rmax, intervals[i][1]);
            }
        }
        return ans;
    }
};
