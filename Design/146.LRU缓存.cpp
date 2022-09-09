#include <unordered_map>
#include <list>
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
    Node *head, *tail;
    int size, cap;
};

class LRUCache_STL {
public:
    LRUCache_STL(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(!mp.count(key)) {
            return -1;
        }

        auto node = mp[key];
        int val = node->second;

        l.erase(node);
        l.push_front({key, val});

        mp[key] = l.begin();

        return val;
    }

    void put(int key, int value) {
        if(mp.count(key)) {
            auto node = mp[key];
            l.erase(node);
            mp.erase(key);
        }

        if(l.size() == cap) {
            auto back = l.back(); // pair
            l.pop_back();
            mp.erase(back.first);
        }

        l.push_front({key, value});
        mp[key] = l.begin();
    }

    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
