#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(mid+k > arr.size()-1 || abs(arr[mid]-x) <= abs(arr[mid+k]-x)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return vector<int>(arr.begin()+left, arr.begin()+left+k);
    }
};
