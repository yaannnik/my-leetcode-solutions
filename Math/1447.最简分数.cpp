#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                if(gcd(i, j) == 1) {
                    res.emplace_back(to_string(j)+"/"+to_string(i));
                }
            }
        }
        return res;
    }

    int gcd(int x, int y) {
        while(y > 0) {
            x = x % y;
            swap(x, y);
        }
        return x;
    }
};
