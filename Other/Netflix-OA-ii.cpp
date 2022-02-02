#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int func(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n - k + 1; i++) {
            for(int j = k; j < n - i + 1; j++) {
                // start i, length j
                vector<int> tmp = vector<int>(nums.begin() + i, nums.begin() + i + j);
                if(valid(tmp, k)) {
                    res++;
                }
            }
        }
        return res;
    }

    static bool valid(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int& i : nums) {
            mp[i]++;
        }
        int cnt = 0;
        for(auto& p : mp) {
            if(p.second == 1) {
                cnt++;
            }
        }
        return cnt >= k;
    }
};

int main() {
    vector<int> nums = {5,5,5,5};
    int k = 1;
    Solution sol;
    int res = sol.func(nums, k);
    cout << res << endl;
    return 0;
}