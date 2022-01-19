#include <vector>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = monotonic_stack(height);
        // int res = dp(height);
        return res;
    }

    int monotonic_stack(vector<int>& height) {
        if(height.empty()) {
            return 0;
        }
        stack<pair<int, int>> st;
        st.push(pair<int, int>(height[0], 0));
        int i = 1, n = height.size();
        int res = 0;
        while(i < n) {
            while(!st.empty() && st.top().first < height[i]) {
                int bottom = st.top().first;
                st.pop();
                if(!st.empty()) {
                    res += min(st.top().first-bottom, height[i]-bottom) * (i-st.top().second-1);
                }
            }
            st.push(pair<int, int>(height[i], i));
            i++;
        }
        return res;
    }

    int dp(vector<int>& height) {
        int res = 0, n = height.size();
        vector<int> left(n, 0), right(n, 0);
        left.front() = height.front();
        right.back() = height.back();
        for(int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i]);
            right[n-1-i] = max(right[n-i], height[n-1-i]);
        }
        for(int i = 1; i < n - 1; i++) {
            res += min(left[i] - height[i], right[i] - height[i]);
        }
        return res;
    }
};
