#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sections = 1;
        vector<int>::iterator left = arr.end() - 1, right = arr.end();
        while(left > arr.begin()) {
            int tmp = *min_element(left, right);
            if(tmp > *max_element(arr.begin(), left)) {
                // left == arr.begin() 不可能进这个逻辑
                sections++;
                right = left;
                left = right - 1;
            } else {
                left--;
            }
        }
        return sections;
    }
};
