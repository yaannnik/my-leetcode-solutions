#include <vector>
using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size() - 1, y = 0;
        while(x >= 0 && y < matrix[0].size()) {
            if(matrix[x][y] == target) {
                return true;
            } else if(matrix[x][y] > target) {
                x--;
            } else {
                y++;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = -1, end = -1;
        int left = 0, right = matrix.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        end = right;
        left = 0, right = end;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid].back() >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        start = left;
        // cout << start << " " << end << endl;
        for(int i = start; i <= end; i++) {
            int l = 0, r = matrix[i].size() - 1;
            while(l <= r) {
                int m = l + (r - l) / 2;
                if(matrix[i][m] == target) {
                    return true;
                } else if(matrix[i][m] < target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return false;
    }
};