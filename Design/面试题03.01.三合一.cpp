#include <vector>
using namespace std;

class TripleInOne {
public:
    TripleInOne(int stackSize) {
        mem = vector<int>(stackSize * 3);
        ptr0 = -3;
        ptr1 = -2;
        ptr2 = -1;
    }

    void push(int stackNum, int value) {
        if(stackNum == 0 && ptr0 + 3 < mem.size()) {
            ptr0 += 3;
            mem[ptr0] = value;
        }
        if(stackNum == 1 && ptr1 + 3 < mem.size()) {
            ptr1 += 3;
            mem[ptr1] = value;
        }
        if(stackNum == 2 && ptr2 + 3 < mem.size()) {
            ptr2 += 3;
            mem[ptr2] = value;
        }
    }

    int pop(int stackNum) {
        if(stackNum == 0 && ptr0 >= 0) {
            ptr0 -= 3;
            return mem[ptr0 + 3];
        }
        if(stackNum == 1 && ptr1 >= 0) {
            ptr1 -= 3;
            return mem[ptr1 + 3];
        }
        if(stackNum == 2 && ptr2 >= 0) {
            ptr2 -= 3;
            return mem[ptr2 + 3];
        }
        return -1;
    }

    int peek(int stackNum) {
        if(stackNum == 0 && ptr0 >= 0) {
            return mem[ptr0];
        }
        if(stackNum == 1 && ptr1 >= 0) {
            return mem[ptr1];
        }
        if(stackNum == 2 && ptr2 >= 0) {
            return mem[ptr2];
        }
        return -1;
    }

    bool isEmpty(int stackNum) {
        if(stackNum == 0) {
            return ptr0 < 0;
        }
        if(stackNum == 1) {
            return ptr1 < 0;
        }
        if(stackNum == 2) {
            return ptr2 < 0;
        }
        return false;
    }
    vector<int> mem;
    int ptr0, ptr1, ptr2;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
