#include <vector>
using namespace std;

class StupidSolution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        vector<int> prefix(n), postfix(n);
        prefix[0] = nums[0];
        postfix[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
            postfix[n - 1 - i] = postfix[n - i] + nums[n - 1 - i];
            // cout << prefix[i] << " " << postfix[n - i - 1] << endl;
        }

        if(postfix[1] == 0) {
            return 0;
        }

        for(int i = 1; i < n - 1; i++) {
            if(prefix[i - 1] == postfix[i + 1]) {
                return i;
            }
        }


        if(prefix[n - 2] == 0) {
            return n - 1;
        }

        return -1;
    }
};

class SmartSolution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(left == sum - left - nums[i]) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};
