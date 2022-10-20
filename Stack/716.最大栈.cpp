#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

class MaxStack {
public:
    MaxStack() {
        id = 0;
    }

    void push(int x) {
        st.push({x, id});
        pq.push({x, id});
        id++;
    }

    int pop() {
        while(removedId.count(st.top().second)) {
            st.pop();
        }
        auto [num, id] = st.top();
        st.pop();
        removedId.insert(id);
        return num;
    }

    int top() {
        while(removedId.count(st.top().second)) {
            st.pop();
        }
        return st.top().first;
    }

    int peekMax() {
        while(removedId.count(pq.top().second)) {
            pq.pop();
        }
        return pq.top().first;
    }

    int popMax() {
        while(removedId.count(pq.top().second)) {
            pq.pop();
        }
        auto [num, id] = pq.top();
        pq.pop();
        removedId.insert(id);
        return num;
    }

    int id;
    unordered_set<int> removedId;
    stack<pair<int, int>> st;
    priority_queue<pair<int, int>> pq;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
