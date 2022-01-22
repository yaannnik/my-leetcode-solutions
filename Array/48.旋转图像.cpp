#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /**
         * 先上下翻转
         * 再转置
         */
        int n = matrix.size();
        for(int i = 0; i < n/2; i++) {
            swap(matrix[i], matrix[n-1-i]);
        }
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
