#include <vector>
#include <deque>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }

    void dfs(vector<NestedInteger> &nestedList) {
        for(auto& nest : nestedList) {
            if(nest.isInteger()) {
                dq.push_back(nest.getInteger());
            } else {
                dfs(nest.getList());
            }
        }
    }

    int next() {
        int res = dq.front();
        dq.pop_front();
        return res;
    }

    bool hasNext() {
        return !dq.empty();
    }

    deque<int> dq;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
