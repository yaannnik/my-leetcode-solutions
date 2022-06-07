#include <vector>
#include <string>
using namespace std;

class Trie {
public:
    Trie() {
        children = vector<Trie*>(26, nullptr);
        isEnd = false;
    }

    void insert(string word) {
        Trie* r = this;
        for(char& ch : word) {
            int k = ch - 'a';
            if(r->children[k] == nullptr) {
                r->children[k] = new Trie();
            }
            r = r->children[k];
        }
        r->isEnd = true;
    }

    bool search(string word) {
        Trie* r = this;
        for(char& ch : word) {
            int k = ch - 'a';
            if(r->children[k] == nullptr) {
                return false;
            }
            r = r->children[k];
        }
        return r->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* r = this;
        for(char& ch : prefix) {
            int k = ch - 'a';
            if(r->children[k] == nullptr) {
                return false;
            }
            r = r->children[k];
        }
        return true;
    }

    vector<Trie*> children;
    bool isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
