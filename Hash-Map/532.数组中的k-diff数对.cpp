#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int> st1;
        set<vector<int>> st2;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int& num : nums) {
            if(st1.count(num-k)) {
                if(!st2.count({num-k, num})) {
                    res++;
                    st2.insert({num-k, num});
                }
            }
            st1.insert(num);
        }
        return res;
    }
};
