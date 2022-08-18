#include <vector>
using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        _data = vector<int>(k + 1);
        head = 0;
        tail = 0;
        capacity = k + 1;
    }

    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }
        head = (head - 1 + capacity) % capacity;
        _data[head] = value;
        return true;
    }

    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }
        _data[tail] = value;
        tail = (tail + 1) % capacity;
        return true;
    }

    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        head = (head + 1) % capacity;
        return true;
    }

    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }
        tail = (tail - 1 + capacity) % capacity;
        return true;
    }

    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return _data[head];
    }

    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return _data[(tail - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return head == tail;
    }

    bool isFull() {
        return (tail + 1) % capacity == head;
    }

    vector<int> _data;
    // head是队列头的元素的位置，tail是队列尾元素的下一个位置
    // 所以capacity = k + 1
    int head, tail;
    int capacity;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
