#include <queue>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        qu.push(t);
        while(qu.front()  < t - 3000) {
            qu.pop();
        }
        return qu.size();
    }

    queue<int> qu;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
