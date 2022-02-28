#include <vector>
using namespace std;

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            bool check = [&]() {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (i == j) {
                            continue;
                        }
                        if (statements[i][j] == 0) { // i 和 j 必有一个是坏人
                            if ((mask & (1 << i)) && (mask & (1 << j))) {
                                return false;
                            }
                        }
                        else if (statements[i][j] == 1) { // j 是好人或者i是坏人
                            if ((mask & (1 << i)) && !(mask & (1 << j))) {
                                return false;
                            }
                        }
                    }
                }
                return true;
            }();
            if (check) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
        return ans;
    }
};
