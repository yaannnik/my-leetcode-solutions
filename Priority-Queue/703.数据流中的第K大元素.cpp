#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        return a > b;
    }
};

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;

        for(int& num : nums) {
            pq.push(num);
        }
    }

    int add(int val) {
        pq.push(val);
        while(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }

    int k;
    vector<int> nums;
    priority_queue<int, vector<int>, cmp> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */