#include <set>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int res = 0;
        for(int i = left; i <= right; i++) {
            int k = count(i);
            if(st.count(k)) {
                // cout << i << " " << k << endl;
                res++;
            }
        }
        return res;
    }

    int count(int n) {
        int cnt = 0;
        while(n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }
};
