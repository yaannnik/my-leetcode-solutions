#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        int dir = 0; // 0 for right, 1 for down, 2 for left, 3 for up
        int r = 0, c = 0;
        for(int i = 1; i <= n * n; i++) {
            // cout << r << " " << c << endl;
            res[r][c] = i;
            if(dir == 0) {
                if(c + 1 < n && res[r][c + 1] == -1) {
                    c++;
                } else {
                    dir = 1;
                    r++;
                }
            } else if(dir == 1) {
                if(r + 1 < n && res[r + 1][c] == -1) {
                    r++;
                } else {
                    dir = 2;
                    c--;
                }
            } else if(dir == 2) {
                if(c - 1 >= 0 && res[r][c - 1] == -1) {
                    c--;
                } else {
                    dir = 3;
                    r--;
                }
            } else {
                if(r - 1 >= 0 && res[r - 1][c] == -1) {
                    r--;
                } else {
                    dir = 0;
                    c++;
                }
            }
        }
        return res;
    }
};
