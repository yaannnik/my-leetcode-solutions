#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }

    static int countOne(int num) {
        int res = 0;
        while(num > 0) {
            res += (num & 1);
            num >>= 1;
        }
        return res;
    }

    static bool cmp(int x, int y) {
        return countOne(x) == countOne(y) ? x < y : countOne(x) < countOne(y);
    }
};
