#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> busy;
        for(int i = 0; i < n; i++) {
            if(hours[i] > 8) {
                busy.emplace_back(1);
            } else {
                busy.emplace_back(-1);
            }
        }
        vector<int> preSum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            preSum[i+1] = preSum[i] + busy[i];
        }
        // 找左边界，左边界的值要尽可能小
        stack<int> st;
        int res = 0;
        for(int i = 0; i < preSum.size(); i++) {
            if(st.empty() || preSum[st.top()] > preSum[i]) {
                st.push(i);
            }
        }
        // 找右边界
        int i = n;
        while(i > res) {
            while(!st.empty() && preSum[st.top()] < preSum[i]) {
                res = max(res, i - st.top());
                st.pop();
            }
            i--;
        }
        return res;
    }
};