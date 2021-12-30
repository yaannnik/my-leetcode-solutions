#include<vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;

        for(int i = 1; i < arr.size() - 1; i++) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                res = max(res, mountainLength(arr, i));
            }
        }

        return res;
    }

    int mountainLength(vector<int>& arr, int peak) {
        int i = peak, j = peak;

        while(i > 0 && arr[i] > arr[i-1]) {
            i--;
        }

        while(j < arr.size()-1 && arr[j] > arr[j+1]) {
            j++;
        }

        return j - i + 1;
    }
};
