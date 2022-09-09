#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> starts;
        for(int i = 0; i < m; i++) {
            starts.emplace_back(i, 0);
        }
        for(int j = 0; j < n; j++) {
            starts.emplace_back(0, j);
        }
        for(auto& [x, y] : starts) {
            int row = x, col = y;
            while(row + 1 < m && col + 1 < n) {
                if(matrix[row + 1][col + 1] != matrix[row][col]) {
                    return false;
                }
                row++;
                col++;
            }
        }
        return true;
    }
};
