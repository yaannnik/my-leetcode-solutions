#include <string>
#include <vector>
using namespace std;

class Trie {
public:
    string word;
    vector<Trie*> children;
    Trie() {
        children = vector<Trie*>(26, nullptr);
        word = "";
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
        r->word = word;
        // cout << r->word << endl;
    }

    bool find(string word) {
        Trie* r = this;
        for(char& ch : word) {
            int k = ch - 'a';
            if(r->children[k] == nullptr || r->children[k]->word == "") { // 这里保证了路径中的每个节点都必须构成词
                return false;
            }
            r = r->children[k];
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        Trie* root = new Trie();

        for(string& word :words) {
            // cout << word << endl;
            root->insert(word);
        }

        for(string& word : words) {
            if(root->find(word)) {
                if(word.size() > res.size() || (word.size() == res.size() && word < res)) {
                    res = word;
                }
            }
        }

        return res;
    }
};
