#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(-1);
        int n = heights.size();
        int res = 0;
        stack<int> st;
        // 单调递增栈：栈内相邻的两个元素，在原数组中，他们之间的元素都比两端大
        for(int i = 0; i < n ; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int left = 0;
                // 如果栈为空，说明之前所有的元素都比当前出栈的元素大。不为空，则说明栈顶到出栈元素之前的元素都比出栈元素大
                if(st.empty()) {
                    left = -1;
                } else {
                    left = st.top();
                }
                int right = i;
                int w = right - left - 1; // heights[left+1:right-1]的面积
                res = max(res, w * h);
            }
            st.push(i);
        }
        return res;
    }
};
