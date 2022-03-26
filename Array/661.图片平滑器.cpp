#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dx;
    vector<int> dy;
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        dx = {-1, 0, 1};
        dy = {-1, 0, 1};
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < img.size(); i++) {
            for(int j = 0; j < img[0].size(); j++) {
                res[i][j] = helper(i, j, img);
            }
        }
        return res;
    }

    int helper(int x, int y, vector<vector<int>>& img) {
        int cnt = 0, grey = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j ++) {
                int nx = x + dx[i];
                int ny = y + dy[j];
                if(nx >= 0 && nx < img.size() && ny >= 0 && ny < img[0].size()) {
                    grey += img[nx][ny];
                    cnt++;
                }
            }
        }
        return (grey / cnt);
    }
};
