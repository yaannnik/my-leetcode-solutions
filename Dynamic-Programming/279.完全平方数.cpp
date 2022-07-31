#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                int m = INT_MAX;
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

class Solution2 {
public:
    int numSquares(int n) {
        unordered_set<int> visited;
        queue<int> qu;
        qu.emplace(0);
        int level = 0;
        while(!qu.empty()) {
            int l = qu.size();
            for(int i = 0; i < l; i++) {
                int sum = qu.front();
                qu.pop();
                for(int j = 1; j <= n; j++) {
                    if(sum + (j * j) == n) {
                        return level + 1;
                    }
                    if(sum + (j * j) > n) {
                        break;
                    }
                    if(!visited.count(sum + (j * j))) {
                        qu.emplace(sum + (j * j));
                        visited.insert(sum + (j * j));
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
