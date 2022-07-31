#define uint32_t unsigned int
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++) {
            uint32_t bit = (n >> i) & 1;
            res += bit;
            if(i < 31) {
                res <<= 1;
            }
        }
        return res;
    }
};
