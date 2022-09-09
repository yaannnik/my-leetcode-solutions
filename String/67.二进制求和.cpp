#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int pa = m - 1, pb = n - 1;
        int aa = 0, bb = 0, cc = 0;
        string res = "";
        while(pa >= 0 && pb >= 0) {
            aa = a[pa--] - '0';
            bb = b[pb--] - '0';
            auto [d, c_] = addBits(aa, bb, cc);

            res = to_string(d) + res;
            cc = c_;
        }

        while(pa >= 0) {
            aa = a[pa--] - '0';
            auto [d, c_] = addBits(aa, 0, cc);

            res = to_string(d) + res;
            cc = c_;
        }

        while(pb >= 0) {
            bb = b[pb--] - '0';
            auto [d, c_] = addBits(0, bb, cc);

            res = to_string(d) + res;
            cc = c_;
        }

        if(cc > 0) {
            res = to_string(cc) + res;
        }
        return res;
    }

    pair<int, int> addBits(int a, int b, int c) {
        int sum = a + b + c;
        if(sum == 0) {
            return {0, 0};
        } else if(sum == 1) {
            return {1, 0};
        } else if(sum == 2) {
            return {0, 1};
        } else {
            return {1, 1};
        }
    }
};
