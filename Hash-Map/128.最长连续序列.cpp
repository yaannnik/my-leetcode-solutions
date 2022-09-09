#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique_nums;
        for(int& num : nums) {
            unique_nums.insert(num);
        }
        int res = 0;
        for(int num : unique_nums) {
            if(!unique_nums.count(num-1)) {
                int p = num;
                int len = 1;
                while(unique_nums.count(p + 1)) {
                    p += 1;
                    len++;
                }
                res = max(res, len);
            }

        }
        return res;
    }
};
