#include <unordered_set>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        return a > b;
    }
};

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        smallest = 1;
    }

    int popSmallest() {
        int res = 0;
        if(addedNums.empty()) {
            res = smallest;
            smallest++;
        } else {
            res = pq.top();
            pq.pop();
            addedNums.erase(res);
        }
        return res;
    }

    void addBack(int num) {
        if(num < smallest) {
            if(!addedNums.count(num)) {
                addedNums.insert(num);
                pq.push(num);
            }
        }
    }

    unordered_set<int> addedNums;
    priority_queue<int, vector<int>, cmp> pq;
    int smallest;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
