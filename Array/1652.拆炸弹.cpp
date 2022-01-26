#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if(k == 0) {
            return res;
        }
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 1; j <= abs(k); j++) {
                sum += k >= 0 ? code[(i+j)%n] : code[(i-j+n)%n];
            }
            res[i] = sum;
        }
        return res;
    }
};
