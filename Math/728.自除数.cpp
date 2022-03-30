class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++) {
            if(helper(i)) {
                res.emplace_back(i);
            }
        }
        return res;
    }

    bool helper(int n) {
        int val = n;
        while(n > 0) {
            int div = n % 10;
            if(div == 0 || val % div != 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
};
