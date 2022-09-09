#include <vector>
using namespace std;

class On {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), postfix(n);
        prefix[0] = nums[0];
        postfix[n-1] = nums[n-1];
        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i] * prefix[i-1];
            postfix[n-1-i] = nums[n-1-i] * postfix[n-i];
        }
        vector<int> res(n);
        res[0] = postfix[1];
        res[n-1] = prefix[n-2];
        for(int i = 1; i < n - 1; i++) {
            res[i] = prefix[i-1] * postfix[i+1];
        }
        return res;
    }
};

class O1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = 1;

        vector<int> res(n, 1);
        for(int i = 0; i < n; i++) {
            res[i] *= left;
            left *= nums[i];

            res[n - 1 - i] *= right;
            right *= nums[n - 1 - i];
        }

        return res;
    }
};
