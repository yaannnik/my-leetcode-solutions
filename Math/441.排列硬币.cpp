using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int rows = 0;
        while(n >= rows + 1) {
            n -= (rows + 1);
            rows++;
        }
        return rows;
    }
};
