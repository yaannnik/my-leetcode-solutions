#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[intervals[i][0]] = i;
        }
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        vector<int> res(n, -1);
        for(int i = 0; i < n - 1; i++) {
            int tmp = binarySearch(intervals, i, i, n - 1);
            if(tmp != INT_MIN) {
                res[mp[intervals[i][0]]] = mp[tmp];
            }
        }
        return res;
    }

    int binarySearch(vector<vector<int>>& intervals, int target, int l, int r) {
        int left = l, right = r;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(intervals[mid][0] < intervals[target][1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if(left > r) {
            return INT_MIN;
        }
        return intervals[left][0];
    }
};
