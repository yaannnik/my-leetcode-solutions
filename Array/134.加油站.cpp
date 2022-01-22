#include <vector>
using namespace std;

/**
 * 一次遍历法，车能开完全程需要满足两个条件：
 * 车从i站能开到i+1。
 * 所有站里的油总量 >= 车子的总耗油量。
 * 假设从编号为0站开始，一直到k站都正常，在开往k+1站时车子没油了，这时，应该将起点设置为k+1站。
 *
 * 为什么应该将起始站点设为k+1？Explanation:
 * 如果x到不了y+1（但能到y），那么从x到y的任一点出发都不可能到达y+1。
 * 因为从其中任一点出发的话，相当于从0开始加油，而如果从x出发到该点则不一定是从0开始加油，可能还有剩余的油。
 * 既然不从0开始都到不了y+1，那么从0开始就更不可能到达y+1了。
 *
 * 为什么如果k+1->end全部可以正常通行，且rest>=0就可以说明车子从k+1站点出发可以开完全程？Explanation
 * 因为，起始点将当前路径分为A、B两部分。其中，必然有 (1)A部分剩余油量<0。(2)B部分剩余油量>0。
 * 所以，无论多少个站，都可以抽象为两个站点（A、B）。(1)从B站加满油出发，(2)开往A站，车加油，(3)再开回B站的过程。
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0, run = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i){
            run += (gas[i] - cost[i]);
            // k+1开始要把0->k+1的补上
            rest += (gas[i] - cost[i]);
            if (run < 0){
                start = i + 1;
                run = 0;
            }
        }
        return rest < 0 ? -1: start;
    }
};
