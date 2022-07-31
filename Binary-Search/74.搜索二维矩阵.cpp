#include <vector>
using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int rows = matrix.size();
        bool res = false;
        for(int i = rows-1; i >= 0; i--) {
            if(target >= matrix[i][0]) {
                return binarySearch(matrix[i], target);
            }
        }
        return false;
    }

    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1, col = -1;
        int left = 0, right = matrix.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if(right < 0) {
            return false;
        }
        row = right;
        left = 0, right = matrix[row].size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[row][mid] == target) {
                return true;
            } else if(matrix[row][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
