#include<unordered_map>
using namespace std;

struct Node {
    int key, val;
    Node* prev;
    Node* next;
    Node(): key(0), val(0), prev(nullptr), next(nullptr) {};
    Node(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {};
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if(cache.find(key) == cache.end()) {
            cache[key] = new Node(key, value);
            addToHead(cache[key]);
            size++;
            if(size > cap) {
                Node* tmp = removeTail();
                cache.erase(tmp->key);
                delete tmp;
                size--;
            }
        } else {
            cache[key]->val = value;
            moveToHead(cache[key]);
        }
    }

    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

    unordered_map<int, Node*> cache;
    Node* head, *tail;
    int size, cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
