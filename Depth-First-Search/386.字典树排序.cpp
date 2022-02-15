#include <vector>
using namespace std;

class Solution {
public:
    vector <int> res;
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++) {
            dfs(i, n);
        }
        return res;
    }

    void dfs(int num, int target) {
        if(num > target) {
            return;
        }
        res.emplace_back(num);
        for(int i = 0; i <= 9; i++) {
            dfs(num * 10 + i, target);
        }
    }
};
