using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x > 0 || y > 0) {
            int bitx = x & 1, bity = y & 1;
            int dist = bitx ^ bity;
            res += dist;
            x >>= 1;
            y >>= 1;
        }
        return res;
    }
};
