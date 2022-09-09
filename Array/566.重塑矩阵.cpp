#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size(), cols = mat[0].size();
        if((rows == r && cols == c) || (r * c != rows * cols)) {
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int index = i * cols + j;
                res[index / c][index % c] = mat[i][j];
            }
        }
        return res;
    }
};
