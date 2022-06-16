#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        if(!qu1.empty()) {
            qu1.push(x);
        } else {
            qu2.push(x);
        }
    }

    int pop() {
        if(qu1.empty()) {
            while(qu2.size() > 1) {
                int front = qu2.front();
                qu2.pop();
                qu1.push(front);
            }
            int res = qu2.front();
            qu2.pop();
            return res;
        } else {
            while(qu1.size() > 1) {
                int front = qu1.front();
                qu1.pop();
                qu2.push(front);
            }
            int res = qu1.front();
            qu1.pop();
            return res;
        }
    }

    int top() {
        if(qu1.empty()) {
            while(qu2.size() > 1) {
                int front = qu2.front();
                qu2.pop();
                qu1.push(front);
            }
            int res = qu2.front();
            qu2.pop();
            qu1.push(res);
            return res;
        } else {
            while(qu1.size() > 1) {
                int front = qu1.front();
                qu1.pop();
                qu2.push(front);
            }
            int res = qu1.front();
            qu1.pop();
            qu2.push(res);
            return res;
        }
    }

    bool empty() {
        return qu1.empty() && qu2.empty();
    }

    queue<int> qu1, qu2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
