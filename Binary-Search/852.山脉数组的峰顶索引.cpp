#include <vector>
using namespace std;

class Solution1 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(mid == arr.size()-1 || arr[mid] > arr[mid+1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class Solution2 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(mid == 0 || arr[mid] > arr[mid - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
