class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 0;
        
        for(int i = 0; n > 0; n -= i) {
            if(n % (++i) == 0) {
                res++;
            }
            
        }
        
        return res;
    }
};

