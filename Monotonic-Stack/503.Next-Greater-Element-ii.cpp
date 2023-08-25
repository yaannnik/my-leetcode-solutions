#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n * 2, -1);
        stack<int> st;
        int i = 0;
        while(i < n * 2) {
            while(!st.empty() && nums[i%n] > nums[st.top()%n]) {
                auto top = st.top();
                st.pop();
                res[top] = nums[i%n];
            }
            st.push(i);
            i++;
        }

        return vector<int>(res.begin(), res.begin()+n);
    }
};
