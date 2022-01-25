#include <vector>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = profit.size();
        vector<vector<int>> tmp;
        for(int i = 0; i < profit.size(); i++) {
            tmp.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(tmp.begin(), tmp.end(), [&](vector<int>& a, vector<int>& b){return a[1] < b[1];});

        vector<int> dp(n + 1, 0); // max profit for i-th job, we can choose to do i-th or not
        for(int i = 0; i < n; i++) {
            int max_profit = 0;
            for(int j = i - 1; j >= 0; j--) {
                if(tmp[j][1] <= tmp[i][0]) {
                    // before choose i-th job, max profit we can get
                    max_profit = max(max_profit, dp[j+1]);
                    break;
                }
            }
            // for i-th job, max profit comes from whether choose i-th job or not
            dp[i+1] = max(dp[i], max_profit+tmp[i][2]);
        }
        return dp.back();
    }
};
