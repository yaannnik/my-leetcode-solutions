#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        //当前位置能跳的最远点
        int max_dist = 0;
        //上一次跳跃的最远边界
        int tmp_edge = 0;
        int steps = 0;
        //不用考虑最后一个位置，因为从最后一个位置之前总能跳过去
        for(int i = 0; i < nums.size() - 1; i++) {
            max_dist = max(max_dist, i + nums[i]);
            if(i == tmp_edge) {
                tmp_edge = max_dist;
                steps++;
            }
        }
        return steps;
    }
};
