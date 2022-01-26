#include <vector>
#include <unordered_map>
using namespace std;

class DetectSquares {
public:
    DetectSquares() {
        cnt = vector<vector<int>>(1001, vector<int>(1001, 0));
    }

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[x][y]++;
        mp[x].emplace_back(y);
    }

    int count(vector<int> point) {
        int px = point[0], py = point[1];
        int res = 0;
        for(int& y : mp[px]) {
            int side = abs(py - y);
            if(side == 0) continue;
            // (px, py), (px, y), (px +- side, py), (px +- side, y)
            if(px + side >= 0 && px + side <= 1000) {
                res += cnt[px + side][y] * cnt[px + side][py];
            }
            if(px - side >= 0 && px - side <= 1000) {
                res += cnt[px - side][y] * cnt[px - side][py];
            }
        }
        return res;
    }

    vector<vector<int>> cnt;
    unordered_map<int, vector<int>> mp;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
