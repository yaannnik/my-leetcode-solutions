#include <vector>
#include <queue>
using namespace std;

struct cmp {
    /*
     * 短的区间在上
     * 若长度相同，尾值小的在上
     */
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[1] == b[1] ? a[1] - a[0] > b[1] - b[0] : a[1] > b[1];
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(int& num : nums) {
            while(!pq.empty() && num > pq.top()[1] + 1) {
                auto top = pq.top();
                pq.pop();
                if(top[1] - top[0] + 1 < 3) {
                    return false;
                }
            }
            if(pq.empty() || num == pq.top()[1]) {
                pq.push({num, num});
            } else {
                auto seq = pq.top();
                pq.pop();
                pq.push({seq[0], num});
            }
        }
        while(!pq.empty()) {
            auto seq = pq.top();
            pq.pop();
            if(seq[1] - seq[0] + 1 < 3) {
                return false;
            }
        }
        return true;
    }
};
