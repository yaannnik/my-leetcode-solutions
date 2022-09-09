#include <string>
using namespace std;

class Node {
public:
    Node(string url_ = "", Node* prev_ = nullptr, Node* next_ = nullptr) {
        prev = prev_;
        next = next_;
        url = url_;
    }

    Node *prev, *next;
    string url;
};

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        visiting = head;
    }

    void visit(string url) {
        visiting->next = new Node(url);
        visiting->next->prev = visiting;
        visiting = visiting->next;
    }

    string back(int steps) {
        for(int i = 0; i < steps; i++) {
            if(visiting->prev) {
                visiting = visiting->prev;
            } else {
                return visiting->url;
            }
        }
        return visiting->url;
    }

    string forward(int steps) {
        for(int i = 0; i < steps; i++) {
            if(visiting->next) {
                visiting = visiting->next;
            } else {
                return visiting->url;
            }
        }
        return visiting->url;
    }

    Node* head;
    Node* visiting;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
