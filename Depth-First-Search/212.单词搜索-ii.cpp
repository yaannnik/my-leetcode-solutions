#include <vector>
#include <string>
#include <set>
using namespace std;

class Trie {
public:
    Trie() {
        children = vector<Trie*>(26);
        word = "";
    }

    void insert(string word) {
        Trie* r = this;
        for(char& ch : word) {
            int k = ch - 'a';
            if(r->children[k] == nullptr) {
                r->children[k] = new Trie();
                // cout << ch << endl;
            }
            r = r->children[k];
        }
        r->word = word;
        // cout << r->word << endl;
    }

    vector<Trie*> children;
    string word;
};

class Solution {
public:
    set<string> res;
    vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(string& word : words) {
            // cout << word << endl;
            root->insert(word);
        }
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int k = board[i][j] - 'a';
                if(root->children[k] != nullptr) {
                    // cout << board[i][j] << endl;
                    dfs(i, j, board, visited, root->children[k]);
                }

            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited, Trie* root) {
        visited[x][y] = true;
        if(root->word != "") {
            res.insert(root->word);
            root->word = "";
        }
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < 4; i++) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                int kk = board[nx][ny] - 'a';
                if(root->children[kk] != nullptr) {
                    // cout << board[nx][ny] << endl;
                    dfs(nx, ny, board, visited, root->children[kk]);
                }
            }
        }
        visited[x][y] = false;
    }
};
