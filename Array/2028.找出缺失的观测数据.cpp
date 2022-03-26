#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = (m + n) * mean, sum_m = accumulate(rolls.begin(), rolls.end(), 0);

        if(sum - sum_m > n * 6 || sum - sum_m < n) {
            return {};
        }

        int sum_n = sum - sum_m, avg_n = sum_n / n, res_n = sum_n - avg_n * n;

        vector<int> res(n, avg_n);
        for(int i = 0; i < res_n; i++) {
            res[i] += 1;
        }
        return res;
    }
};
