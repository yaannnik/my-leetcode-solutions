#define uint32_t unsigned int
using namespace std;

class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n > 0) {
            res += (n & 1);
            n >>= 1;
        }
        return res;
    }
};

class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        while(n > 0) {
            n &= (n - 1);
            ones++;
        }
        return ones;
    }
};
