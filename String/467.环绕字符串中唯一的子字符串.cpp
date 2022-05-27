#include <vector>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26);
        int k = 0;
        for(int i = 0; i < p.size(); i++) {
            if(i > 0 && (p[i] - p[i-1] == 1 || p[i] - p[i-1] == -25)) {
                k++;
            } else {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
