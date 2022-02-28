#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> res(2, vector<int>(n, 0));
        int sum0 = 0, sum1 = 0;
        for(int i = 0; i < n; i++) {
            if(colsum[i] == 2) {
                res[0][i] = 1;
                res[1][i] = 1;
                sum0 += 1;
                sum1 += 1;
            }
            if(sum0 > upper || sum1 > lower) {
                return {};
            }
        }
        for(int i = 0; i < n; i++) {
            if(colsum[i] == 1) {
                if(sum0 < upper) {
                    res[0][i] = 1;
                    sum0 += 1;
                } else {
                    res[1][i] = 1;
                    sum1 += 1;
                }
            }
            if(sum0 > upper || sum1 > lower) {
                return {};
            }
        }
        if(sum0 != upper || sum1 != lower) {
            return {};
        }
        return res;
    }
};
