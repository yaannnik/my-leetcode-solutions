#include <math.h>
#include <numeric>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool flag = x > 0;
        x = abs(x);
        long res = 0;
        while(x > 0) {
            int d = x % 10;
            res = res * 10 + d;
            x /= 10;
        }
        res = flag ? res : -res;
        if(res < INT_MIN || res > INT_MAX) {
            return 0;
        }
        return res;
    }
};
