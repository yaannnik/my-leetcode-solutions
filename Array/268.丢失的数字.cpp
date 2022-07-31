#include <vector>
using namespace std;

class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        vector<int> cnt(n, 0);
        for(int& num : nums) {
            cnt[num]++;
        }
        return min_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (0 + n) * (n + 1) / 2;
        for(int& num : nums) {
            sum -= num;
        }
        return sum;
    }
};
