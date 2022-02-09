#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        if(n < 3) {
            return 0;
        }
        for(int i = 0; i < n; i++) {
            map<int, int> mp;
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                int dist = (points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                res += mp[dist] * 2;
                mp[dist]++;
            }
        }
        return res;
    }
};
