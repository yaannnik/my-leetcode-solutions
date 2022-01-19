#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(valid(mid, h, piles)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool valid(int k, int h, vector<int> piles) {
        int time = 0;
        // 遍历piles更省时
        for(int p = 0; p < piles.size(); p++) {
            time += piles[p] / k;
            if(piles[p] % k != 0) {
                time += 1;
            }
            if(time > h) {
                return false;
            }
        }
        return true;
    }
};
