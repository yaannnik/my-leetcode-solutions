#include <vector>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxRight(n, 0);
        for(int i = 0; i < ranges.size(); i++) {
            int range = ranges[i];
            int left = max(0, i - range), right = min(n, i + range);
            // 能覆盖到 j 的水龙头最右侧可以覆盖到哪里
            for(int j = left; j < right; j++) {
                maxRight[j] = max(maxRight[j], right);
            }
        }

        int res = 0, cur = 0;
        while(cur < n) {
            if(maxRight[cur] == 0) {
                return -1;
            }
            // 每次都跳到最右端
            cur = maxRight[cur];
            res++;
        }
        return res;
    }
};
