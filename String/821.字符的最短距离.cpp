#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            res[i] = helper(s, c, i);
        }
        return res;
    }

    int helper(string s, char c, int p) {
        if(c == s[p]) {
            return 0;
        }
        int left = p - 1, right = p + 1;
        int res = INT_MAX;
        while(left >= 0) {
            if(s[left] == c) {
                res = min(res, abs(p - left));
                break;
            } else {
                left--;
            }
        }
        while(right < s.size()) {
            if(s[right] == c) {
                res = min(res, abs(p - right));
                break;
            } else {
                right++;
            }
        }
        return res;
    }
};
