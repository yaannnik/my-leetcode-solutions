#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        /*
         * 证明贪心思路：如果最终得到了pq.top()是奇数，那么它和pq中最小值的差距就一定是答案。
         * 因为此时，对于pq中的最小值而言，不可能再通过翻倍来使得差距缩小。
         * 假设最小值mi是奇数，由于初始时我们已经将所有奇数都翻倍了，
         * 那么它曾经的原始值a（偶数）在一定是曾经作为堆顶被至少除过一次
         * 由于将堆顶除以2的操作不可能使差距变大
         * 则当mi*2作为堆顶时的res一定是大于等于现在的res，因此现在的res就是答案
         */

        priority_queue<int> pq;
        int min_n = INT_MAX;
        for(int& num : nums) {
            if(num % 2 != 0) {
                num *= 2;
            }
            pq.push(num);
            min_n = min(min_n, num);
        }
        int res = INT_MAX;
        while(pq.top() % 2 == 0) {
            int t = pq.top() / 2;
            pq.pop();
            pq.push(t);
            min_n = min(min_n, t);
            res = min(res, pq.top() - min_n);
        }
        return res;
    }
};
