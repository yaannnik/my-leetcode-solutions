#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0;
        // 将角色能力进行排序 如果 角色之间的攻击力相同 则将 防御力较低的排到前面 反之 攻击力按照降序排序
        // 防止同样攻击力之间角色互相比较
        sort(properties.begin(), properties.end(),
             [&](vector<int>& p1, vector<int>& p2){return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] > p2[0];});
        int m = INT_MIN;
        for(int i = 0; i < properties.size(); i++) {
            // 只要前面有防御力更强的，当前就是弱角色
            if(m > properties[i][1]) {
                res++;
            }
            m = max(m, properties[i][1]);
        }
        return res;
    }
};
