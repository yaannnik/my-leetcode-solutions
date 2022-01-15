#include<vector>
#include<stack>
#include<utility>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
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
};
