#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> qu(nums.begin(), nums.end());
        int res;
        for(int i = 0; i < k; i++) {
            res = qu.top();
            qu.pop();
        }
        return res;
    }
};
