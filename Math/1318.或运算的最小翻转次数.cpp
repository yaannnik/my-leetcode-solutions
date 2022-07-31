using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while(a > 0 || b > 0 || c > 0) {
            int bita = a & 1, bitb = b & 1, bitc = c & 1;

            if((bita | bitb) != bitc) {
                if(bitc == 0) {
                    res += (bita + bitb);
                } else {
                    res += 1;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return res;
    }
};
