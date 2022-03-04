#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> sum(n + 1, 0); // n + 1避免[0:i]的情况，sum[j] - sum[i]是[i:j]的和
        for(int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }

        int res = n + 1;
        deque<long> dq;

        for(int i = 0; i < n + 1; i++) {
            while(!dq.empty() && sum[dq.back()] >= sum[i]) {
                /*
                 * 对于新加入的y，前面的P[?]都要比新加入的P[y]要小，比P[y]大的P[?]都要pop掉，甚至如果都比P[y]大，整个队列都要清空。为什么？
                 * 因为只有比P[y]小的P[?]，才能跟y组成，(y,x)组合，使得P[y]-P[x]>=K。
                 * 那些不比P[y]小的P[?]，起不到任何作用，不可能存在一个x让当前的y或者之后的新y满足P[y]-P[x]>=K，也就不可能去更新最小长度。
                 * 因此，只有比 P[y]小的P[?]才有保留的必要。
                 */
                dq.pop_back();
            }
            while(!dq.empty() && sum[i] - sum[dq.front()] >= k ) {
                /*
                 * 为什么当队列里第一个x满足P[y]-P[x]>=K的时候，第一个x可以被pop掉？
                 * 因为此时我们构成了一个P[y]-P[x]>=K，之后这个x就没有作用了。
                 * 为什么这个x没有用了？
                 * 因为即使之后存在某个其他的y'，也可以跟这个x构成P[y]-P[x]>=K，但是因为y'>y，因此次新的长度一定比当前的长度y-x要长，因为可以不用考虑。
                 */
                res = min(res, (int)(i - dq.front()));
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return res < n + 1 ? res : -1;
    }
};
