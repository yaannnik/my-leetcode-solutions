#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        int i = 0;
        while(i < n) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int top = st.top();
                st.pop();
                res[top] = i - top;
            }
            st.push(i);
            i++;
        }
        return res;
    }
};
