#include <vector>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int start = startTime[i], end = endTime[i];
            if(start <= queryTime && queryTime <= end) {
                res++;
            }
        }
        return res;
    }
};
