#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int start = 1; start <= 9; start++) {
            int num = start;
            for(int d = start + 1; d <= 9; d++) {
                num = num * 10 + d;
                if(low <= num && num <= high) {
                    res.emplace_back(num);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
