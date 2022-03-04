#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false; // 边数小于4
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) {
            return false; // 和不是4的倍数
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        // 从大到小排序，优先选用大的边可以令不成功的情况更快返回
        vector<int> bucket(4); // 定义4个边的值
        return dfs(0, matchsticks, sum / 4, bucket);
    }

    bool dfs(int index, vector<int>& matchsticks, int target, vector<int>& bucket) {
        //index为当前遍历到的下标，matchsticks为边长数组，target为目标边长，bucket表示当前每条边的长度
        if (index >= matchsticks.size()) {
            return (bucket[0] == bucket[1]) && (bucket[1] == target) && (bucket[2] == target);
        }// 每条边都用了

        for (int i = 0; i < 4; i++) { // 将当前的边放在4个桶中分别尝试
            if (bucket[i] + matchsticks[index] > target) {
                continue; // 说明不可以放在这个边上
            }
            bucket[i] += matchsticks[index]; // 否则放入该边后继续dfs
            if(dfs(index + 1, matchsticks, target, bucket)) {
                return true;
            }
            bucket[i] -= matchsticks[index]; // 注意回溯的恢复状态
        }
        return false;
    }
};

