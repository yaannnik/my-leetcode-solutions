#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) {
            return 0;
        }
        vector<int> tmp(n, 1);
        tmp[0] = 0;
        tmp[1] = 0;

        int cnt = 0;
        for(int i = 2; i < n; i++) {
            if(tmp[i] == 1) {
                cnt++;
                for(int j = 2 * i; j < n; j += i) {
                    // 质数的倍数不是质数
                    tmp[j] = 0;
                }
            }
        }
        return cnt;
    }
};
