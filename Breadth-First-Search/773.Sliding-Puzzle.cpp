#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int row, col;
    int slidingPuzzle(vector<vector<int>>& board) {
        row = board.size(), col = board[0].size();
        string init = "", target = "";
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                init += board[i][j] + '0';
                target += i * col + j + '1';
            }
        }
        target[target.size()-1] = '0';
        // cout << target << endl;
        if(init == target) {
            return 0;
        }
        queue<pair<string, int>> qu;
        qu.emplace(init, 0);
        set<string> used;

        while(!qu.empty()) {
            auto [status, step] = qu.front();
            qu.pop();
            used.insert(status);
            if(status == target) {
                return step;
            }
            vector<string> nexts = get(status);
            for(string& s : nexts) {

                if(!used.count(s)) {
                    qu.emplace(s, step + 1);
                }
            }
        }
        return -1;
    }

    vector<string> get(string& status) {
        vector<string> res;
        int zero = status.find('0');
        int x = zero / col, y = zero % col;
        if(x - 1 >= 0) {
            swap(status[(x-1) * col + y], status[zero]);
            res.emplace_back(status);
            swap(status[(x-1) * col + y], status[zero]);
        }
        if(x + 1 < row) {
            swap(status[(x+1) * col + y], status[zero]);
            res.emplace_back(status);
            swap(status[(x+1) * col + y], status[zero]);
        }
        if(y - 1 >= 0) {
            swap(status[x * col + y - 1], status[zero]);
            res.emplace_back(status);
            swap(status[x * col + y - 1], status[zero]);
        }
        if(y + 1 < col) {
            swap(status[x * col + y + 1], status[zero]);
            res.emplace_back(status);
            swap(status[x * col + y + 1], status[zero]);
        }
        return res;
    }
};
