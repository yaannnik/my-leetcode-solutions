#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) {
            return 0;
        }
        int res = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == '0') {
                    heights[j] = 0;
                }
                else {
                    heights[j] = heights[j]+1;
                }
            }
            res = max(res, largestRectangle(heights));
        }
        return res;
    }

    int largestRectangle(vector<int> heights) {
        stack<int> s;
        int ans = 0;
        heights.push_back(-1);//保证最后一定能计算出结果
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int h = heights[s.top()];
                s.pop();
                if (s.empty())
                    ans = max(ans, i * h);
                else
                    ans = max(ans, (i - s.top() - 1) * h);//i-1指向的是当前的
            }
            s.push(i);
        }
        return ans;
    }
};
