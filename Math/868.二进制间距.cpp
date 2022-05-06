#include <math.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int res = 0, one = -1;
        int digit = 0;
        while(n > 0) {
            if(n % 2 == 1) {
                if(one != -1) {
                    res = max(res, digit - one);
                }
                one = digit;
            }
            n >>= 1;
            digit++;
        }
        return res;
    }
};
