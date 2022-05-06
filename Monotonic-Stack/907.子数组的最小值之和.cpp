#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int res = 0;
        long long mod = 1E9 + 7;
        stack<int> st;
        arr.emplace_back(0);
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int top = st.top();
                st.pop();
                long left = st.empty() ? top+1 : top-st.top();
                long right = i - top;
                res += (long)(left * right * arr[top])%mod;
                res = res % mod;
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

