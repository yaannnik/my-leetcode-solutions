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
        for(auto list : nestedList) {
            flatten(list);
        }
        i = -1;
    }

    int next() {
        i++;
        return nums[i];
    }

    bool hasNext() {
        return i + 1 < nums.size();
    }

    void flatten(NestedInteger& list) {
        if(list.isInteger()) {
            nums.emplace_back(list.getInteger());
            return;
        }
        vector<NestedInteger> v = list.getList();
        for(auto i : v) {
            flatten(i);
        }
    }

    int i;
    vector<int> nums;
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
