#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeros = 0;
        int n = arr.size();
        for(int& num : arr) {
            if(num == 0) {
                zeros++;
            }
        }
        vector<int> tmp = arr;
        arr = vector<int>(n, 0);
        int i = 0;
        for(int j = 0; j < n; j++) {
            if(i < n) {
                if(tmp[j] != 0) {
                    arr[i++] = tmp[j];
                } else {
                    i += 2;
                }
            }
        }
    }
};
