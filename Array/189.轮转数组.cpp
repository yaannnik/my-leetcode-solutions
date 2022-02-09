#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        int n = nums.size();
        k %= n;
        for(int i = 0; i < n; i++) {
            nums[(i + k) % n] = tmp[i];
        }
    }

    void best(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }

    int gcd(int x, int y) {
        while(y > 0) {
            x = x % y;
            swap(x, y);
        }
        return x;
    }
};
