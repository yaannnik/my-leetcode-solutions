#include <vector>
#include <stack>
using namespace std;

class Solution1 {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;

        stack<int> st1; // 单调递增栈
        vector<int> prev(n);
        for(int i = 0; i < n; i++) {
            while(!st1.empty() && arr[i] <= arr[st1.top()]) {
                st1.pop();
            }
            // 后续的数如果比arr[i]相等或更小，则也不可能大于比arr[i]更大的数；
            // 后续的数如果比arr[i]更大，则到i就会停止
            prev[i] = st1.empty() ? -1 : st1.top();
            st1.push(i);
        }

        stack<int> st2;
        vector<int> back(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!st2.empty() && arr[i] < arr[st2.top()]) {
                st2.pop();
            }
            back[i] = st2.empty() ? n : st2.top();
            st2.push(i);
        }

        long res = 0;
        for(int i = 0; i < n; i++) {
            res += ((long)(i - prev[i]) * (back[i] - i) % mod) * (long)arr[i];
            res %= mod;
        }
        return (int)res;
    }
};

class Solution2 {
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

