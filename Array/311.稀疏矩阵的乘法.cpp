#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int r1 = mat1.size(), c1 = mat1[0].size();
        int r2 = mat2.size(), c2 = mat2[0].size();
        vector<vector<int>> res(r1, vector<int>(c2, 0));
        for(int i = 0; i < r1; i++) {
            for(int k = 0; k < c1; k++) {
                if(mat1[i][k] == 0) continue;
                for(int j = 0; j < c2; j++) {
                    res[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        return res;
    }
};
