#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0; // 当前一圈左上角行号（列号）
        vector<int> res;
        while(rows > start * 2 && cols > start * 2) {
            printMatrixInCircle(matrix, rows, cols, start, res);
            start++;
        }
        return res;
    }

    void printMatrixInCircle(vector<vector<int>>& matrix, int rows, int cols, int start, vector<int>& res) {
        int end_x = cols - 1 - start;
        int end_y = rows - 1 - start;

        // from left to right
        for(int i = start; i <= end_x; i++){
            res.push_back(matrix[start][i]);
        }
        // from top to bottom
        if(start < end_y) {
            for(int i = start + 1; i <= end_y; i++) {
                res.push_back(matrix[i][end_x]);
            }
        }
        // from right to left
        if(start < end_x && start < end_y) {
            for(int i = end_x - 1; i >= start; i--) {
                res.push_back(matrix[end_y][i]);
            }
        }
        // from bottom to top
        if(start < end_x && start < end_y - 1) {
            for(int i = end_y - 1; i >= start + 1; i--) {
                res.push_back(matrix[i][start]);
            }
        }
    }
};
