#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(lessCount(matrix, mid, n) < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int lessCount(vector<vector<int>>& matrix, int mid, int len) {
        int count = 0;
        int row = len - 1, col = 0;
        while(row >= 0 && col < len) {
            if(matrix[row][col] <= mid) {
                count += row + 1; // 此列内的都满足
                col++;
            } else {
                row--; // 此列内本行不满足，减一行
            }
        }
        return count;
    }
};
