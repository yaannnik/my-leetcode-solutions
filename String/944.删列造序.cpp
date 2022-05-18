#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        if(m <= 1) {
            return 0;
        }
        int res = 0;
        for(int col = 0; col < n; col++) {
            for(int row = 1; row < m; row++) {
                if(strs[row][col] < strs[row-1][col]) {
                    // cout << col << endl;
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
