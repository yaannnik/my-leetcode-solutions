#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        st.push(val);
        if(mst.empty() || val <= mst.top()) {
            mst.push(val);
        }
    }

    void pop() {
        int v = st.top();
        st.pop();
        if(v == mst.top()) {
            mst.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mst.top();
    }

    stack<int> st;
    stack<int> mst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
