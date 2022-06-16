#include <numeric>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int two = INT_MIN;
        stack<int> three;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] < two) {
                return true;
            }
            while(!three.empty() && nums[i] > three.top()) {
                two = three.top();
                three.pop();
            }
            three.push(nums[i]);
        }
        return false;
    }
};
