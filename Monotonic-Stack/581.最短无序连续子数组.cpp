#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mi = nums.size(), ma = 0;
        stack<int> st;
        int i = 0;
        int maxVal = -1000;
        while(i < nums.size()) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                mi = min(st.top(), mi);
                maxVal = max(nums[st.top()], maxVal);
                st.pop();
            }
            if(i > mi && nums[i] < maxVal) {
                ma = max(ma, i);
            }
            st.push(i);
            i++;
        }
        return ma - mi + 1 > 0 ? ma - mi + 1 : 0;
    }
};
