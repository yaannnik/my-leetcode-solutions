#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.emplace_back(-1);
        stack<int> st;
        int i = 0;
        while(i < heights.size()) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                if(!st.empty()) {
                    res = max(res, height * (i - st.top() - 1));
                } else {
                    res = max(res, height * i);
                }
            }
            st.push(i);
            i++;
        }
        return res;
    }
};
