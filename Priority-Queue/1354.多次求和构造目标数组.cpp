#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (int& a, int& b) {
        return a < b;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();

        if(n == 1 && target[0] != 1) {
            return false;
        }

        long sum = 0;
        priority_queue<int, vector<int>, cmp> pq;
        for(int& num : target) {
            sum += num;
            pq.emplace(num);
        }

        while(!pq.empty() && pq.top() != 1) {
            long max = pq.top();
            pq.pop();
            sum -= max;

            if (max >= sum) {
                // 如果max一直是最大的情况
                max %= sum;
            } else {
                max -= sum;
            }

            if(sum == 1 && max == 0) {
                // cout << "[1, x] situation" << endl;
                return true;
            }

            sum += max;

            if(max < 1) {
                return false;
            }

            pq.emplace(max);
        }
        return true;
    }
};
