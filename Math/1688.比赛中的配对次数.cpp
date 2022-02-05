class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while(n > 1) {
            int k = n % 2;
            int matches = n / 2;
            res += matches;
            n = matches + k;
        }
        return res;
    }
};
