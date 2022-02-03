#include <vector>
using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibs = fib(k);
        int n = fibs.size(), res = 0;
        for(int i = n - 1; i >= 0; i--) {
            while(k >= fibs[i]) {
                k -= fibs[i];
                res++;
            }
        }
        return res;
    }

    vector<int> fib(int k) {
        vector<int> res = {1, 1};
        while(res.back() <= k) {
            int n = res.size();
            res.emplace_back(res[n-1] + res[n-2]);
        }
        return vector<int>(res.begin(), res.end()-1);
    }
};
