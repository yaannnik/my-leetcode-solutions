#include <set>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    set<vector<int>> on;
    map<int, int> rows, cols, diags1, diags2;
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        for(auto& lamp : lamps) {
            // 标记开着的灯 & 行，列，对角线各被几盏灯照亮
            if(!on.count(lamp)) {
                on.insert(lamp);
                rows[lamp[0]]++;
                cols[lamp[1]]++;
                diags1[lamp[0]+lamp[1]]++;
                diags2[lamp[0]-lamp[1]]++;
            }
        }
        vector<int> res;
        for(auto& query : queries) {
            int row = query[0], col = query[1];
            if(inLight(row, col)) {
                res.emplace_back(1);
                turnOff(row, col, n);
            } else {
                res.emplace_back(0);
            }
        }
        return res;
    }

    bool inLight(int row, int col) {
        // 判断是否被照亮
        return (rows[row] > 0 || cols[col] > 0 || diags1[row+col] > 0 || diags2[row-col] > 0);
    }

    void turnOff(int row, int col, int n) {
        vector<int> dr = {-1, 0, 1, -1, 0, 1, -1, 0, 1}, dc = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        for(int i = 0; i < 9; i++) {
            // 关闭九宫格内的灯，行，列，对角线相应-1
            int nr = row + dr[i], nc = col + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && on.count({nr, nc})) {
                on.erase({nr, nc});
                rows[nr]--;
                cols[nc]--;
                diags1[nr+nc]--;
                diags2[nr-nc]--;
            }
        }
    }
};
