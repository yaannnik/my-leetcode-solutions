class Solution {
public:
    bool hasAlternatingBits(int n) {
        int tmp = n & 1;
        n = n >> 1;

        while(n > 0) {
            if(tmp == (n & 1)) {
                return false;
            }
            tmp = (n & 1);
            n = n >> 1;
        }

        return true;
    }
};
