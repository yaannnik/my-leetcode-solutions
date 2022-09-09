using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        // unordered_set<int> visited;
        // while(n != 1 && !visited.count(n)) {
        //     visited.insert(n);
        //     n = getNext(n);
        // }
        // return n == 1;

        // Floyd cycle
        int slow = n, fast = getNext(n);
        while(fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }

    int getNext(int n) {
        int next = 0;
        while(n > 0) {
            int d = n % 10;
            n /= 10;
            next += d * d;
        }
        return next;
    }
};
