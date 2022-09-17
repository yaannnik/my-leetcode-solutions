#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        unordered_set<int> rows_set, cols_set;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    rows_set.insert(i);
                    cols_set.insert(j);
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(rows_set.count(i) || cols_set.count(j)) {
                    matrix[i][j] = 0;;
                }
            }
        }
    }
};
