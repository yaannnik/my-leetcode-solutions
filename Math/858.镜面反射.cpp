using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int k = 0;
        for(k = 1; k <= p; k++) {
            if(k * q % p == 0) {
                break;
            }
        }
        int UpDown = (k * q) / p; // 判断上下
        int LeftRight = k; // 判断左右

        if(UpDown % 2 == 0) {
            return 0;
        } else {
            if(LeftRight % 2 == 0) {
                return 2;
            }
            else {
                return 1;
            }
        }
    }
};
