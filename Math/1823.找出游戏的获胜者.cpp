#include <queue>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
//        return simulation(n, k);
        return recursion(n, k);
    }

    int simulation(int n, int k) {
        queue<int> qu;
        for(int i = 0; i < n; i++) {
            qu.push(i);
        }
        while(qu.size() > 1) {
            for(int i = 0; i < k - 1; i++) {
                int front = qu.front();
                qu.pop();
                qu.push(front);
            }
            qu.pop();
        }
        int res = qu.front();
        return res + 1;
    }

    int recursion(int n, int k) {
        if(n == 1) {
            return 1;
        }
        return (k + recursion(n - 1, k) - 1) % n + 1;
    }
};
