#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    string word;
    TrieNode() {
        word = "";
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res = {};
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); i++) {
            TrieNode* ptr = root;
            for(int j = 0; j < words[i].size(); j++) {
                if(ptr->children[words[i][j]-'a'] == nullptr) {
                    ptr->children[words[i][j]-'a'] = new TrieNode();
                }
                ptr = ptr->children[words[i][j]-'a'];
            }
            ptr->word = words[i];
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, root, i, j);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* node, int i, int j) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }
        if(board[i][j] == '*' || node->children[board[i][j] - 'a'] == nullptr ) {
            return;
        }
        char tmp = board[i][j];
        node = node->children[tmp - 'a'];
        if(node->word != "") {
            res.emplace_back(node->word);
            node->word = ""; // avoid duplicate
        }
        board[i][j] = '*';
        dfs(board, node, i - 1, j);
        dfs(board, node, i + 1, j);
        dfs(board, node, i, j - 1);
        dfs(board, node, i, j + 1);
        board[i][j] = tmp;
    }

    vector<string> res;
};
