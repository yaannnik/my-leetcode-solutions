class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        _data = vector<int>(k + 1);
        head = 0;
        tail = 0;
        capacity = k + 1;
    }

    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        _data[tail] = value;
        tail = (tail + 1) % capacity;
        return true;
    }

    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        head = (head + 1) % capacity;
        return true;
    }

    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return _data[head];
    }

    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        return _data[(tail - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return head == tail;
    }

    bool isFull() {
        return (tail + 1 + capacity) % capacity == head;
    }

    vector<int> _data;
    int head, tail;
    int capacity;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
