#include <vector>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowmin(m, INT_MAX), colmax(n, INT_MIN);
        for(int i = 0; i < m; i++) {
            rowmin[i] = *min_element(matrix[i].begin(), matrix[i].end());
            for(int j = 0; j < n; j++) {
                colmax[j] = max(colmax[j], matrix[i][j]);
            }
        }
        vector<int> res;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == rowmin[i] && matrix[i][j] == colmax[j]) {
                    res.emplace_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};
