#include <math.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int i = 1; i <= m && i <= mid; i++) {
                cnt += min(mid / i, n); // 第i行内比mid小的个数
            }
            if(cnt < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
