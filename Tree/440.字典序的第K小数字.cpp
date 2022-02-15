using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        // 先访问1开头的节点
        int num = 1;
        k--;
        while(k > 0) {
            long long cnt = 0, start = num, end = num + 1;
            while(start <= n) {
                // 当前节点的子树有多少个子节点
                cnt += min((long long)n + 1, end) - start; // [start, min(n+1, end))的区间
                start *= 10;
                end *= 10;
            }
            if(cnt <= k) {
                // 当前子树下的所有节点小于k，答案不在这颗子树下
                num++;
                k -= cnt;
            } else {
                // 答案在这颗子树下，一层一层开始查找
                num *= 10;
                k--;
            }
        }
        return num;
    }
};
