#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++) {
            res.emplace_back(count(i));
        }
        return res;
    }

    int count(int x) {
        int ones = 0;
        while(x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }
};
