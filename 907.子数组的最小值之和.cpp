/*
 * @@author: yangyi
 */
/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
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
                cout << "left: " << left << endl;
                long right = i - top;
                cout << "right: " << right << endl;
                res += (long)(left * right * arr[top])%mod;
                res = res % mod;
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

