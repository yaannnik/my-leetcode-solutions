#include <vector>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        /*
         * 我们这样来看这个问题，公司首先将这2n个人全都安排飞往 BB 市，再选出n个人改变它们的行程，
         * 让他们飞往A市。如果选择改变一个人的行程，那么公司将会额外付出 price_A - price_B 的费用，
         * 这个费用可正可负。
         * 因此最优的方案是，选出 price_A - price_B 最小的 NN 个人，
         * 让他们飞往 A 市，其余人飞往 B 市。
         * 算法：
         * 按照 price_A - price_B 从小到大排序；
         * 将前 NN 个人飞往 A 市，其余人飞往 B 市，并计算出总费用。
         *
         */
        sort(costs.begin(), costs.end(), [&](vector<int>& a, vector<int>& b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        int N = costs.size();
        int n = N / 2;
        int res = 0;
        for(int i = 0; i < N; i++) {
            if(i < n) {
                res += costs[i][0];
            } else {
                res += costs[i][1];
            }
        }
        return res;
    }
};
