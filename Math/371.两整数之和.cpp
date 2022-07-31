using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) {
            return a;
        }
        // 每一位没有进位的情况
        int sum = a ^ b;
        // 每一位的进位数
        unsigned int carry = (unsigned int)(a & b) << 1;
        return getSum(sum, carry);
    }
};

