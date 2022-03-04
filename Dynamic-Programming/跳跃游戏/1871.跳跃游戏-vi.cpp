#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n), pre(n);
        for(int i = 0; i < minJump; i++) {
            pre[i] = 1; // [0:minJump]不能跳
        }
        // f(i) 的值为 true，当且仅当 s[i] 为 0，并且区间 [left_i, right_i] 中存在一个位置作为下标对应的 f 值也为 true。
        for(int i = minJump; i < n; i++) {
            int left = i - maxJump, right = i - minJump;
            if(s[i] == '0') {
                int sum = pre[right] - (left - 1 >= 0 ? pre[left-1] : 0); // sum = [left : right]求和
                dp[i] = (sum > 0);
            }
            pre[i] = pre[i-1] + dp[i];
        }
        return dp[n-1];
    }
};
