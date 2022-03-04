#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int sum = accumulate(sweetness.begin(), sweetness.end(), 0), avg = sum / (k+1);
        int left = 0, right = avg;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(valid(mid, k, sweetness)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }

    bool valid(int x, int k, vector<int>& sweetness) {
        int cnt = 0, sum = 0;
        for(int& num : sweetness) {
            sum += num;
            if(sum >= x) {
                cnt++;
                sum = 0;
            }
        }
        return cnt >= k + 1;
    }
};
