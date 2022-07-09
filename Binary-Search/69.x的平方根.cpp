using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((long)mid * (long)mid > (long)x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
