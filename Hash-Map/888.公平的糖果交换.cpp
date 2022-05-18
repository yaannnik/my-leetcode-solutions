#include <numbers>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bob = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (bob - alice) / 2;
        // int dis1 = alice - avg, dis2 = bob - avg;
        vector<int> res;
        unordered_set<int> s;
        for(int& i : bobSizes) {
            s.insert(i);
        }
        for(int& i : aliceSizes) {
            if(s.count(delta + i)) {
                res = {i, delta + i};
                break;
            }
        }
        return res;
    }
};
