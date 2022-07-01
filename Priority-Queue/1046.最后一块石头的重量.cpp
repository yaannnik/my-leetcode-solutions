#include <queue>
#include <vector>
using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        return a < b;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, cmp> pq;
        for(int& s : stones) {
            pq.push(s);
        }
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            // cout << a << " " << b << endl;
            if(a == b) {
                continue;
            } else {
                pq.push(abs(a - b));
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
