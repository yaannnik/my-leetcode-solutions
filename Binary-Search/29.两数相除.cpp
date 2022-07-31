#include <numeric>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        dividend = abs(dividend);
        divisor = abs(divisor);

        long long left = 0, right = (long long)dividend;
        while(left <= right) {
            long long mid = left + (right - left) / 2;
            if(mid * divisor > dividend) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        right = neg ? -right : right;
        if(right > (long long)INT_MAX) {
            return INT_MAX;
        } else if(right < (long long)INT_MIN){
            return INT_MIN;
        } else {
            return right;
        }
    }
};
