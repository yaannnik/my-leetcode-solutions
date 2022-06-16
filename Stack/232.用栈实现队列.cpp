#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if(st2.empty()) {
            while(!st1.empty()) {
                int top = st1.top();
                st1.pop();
                st2.push(top);
            }
        }
        int res = st2.top();
        st2.pop();
        return res;
    }

    int peek() {
        if(st2.empty()) {
            while(!st1.empty()) {
                int top = st1.top();
                st1.pop();
                st2.push(top);
            }
        }
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }

    stack<int> st1, st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
