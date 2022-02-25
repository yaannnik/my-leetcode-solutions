#include <string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        char left = 'L'; // 最左默认一个'L'
        int i = 0;
        while(i < n) {
            int j = i;
            // 找一段连续的'.'
            while(j < n && dominoes[j] == '.') {
                j++;
            }
            char right = j < n ? dominoes[j] : 'R';
            if(right == left) {
                // 方向相同，那么这些竖立骨牌也会倒向同一方向
                while(i < j) {
                    dominoes[i++] = left;
                }
            } else if(left == 'R' && right == 'L') {
                // 方向相对，那么就从两侧向中间倒
                int k = j - 1;
                while(i < k) {
                    dominoes[i++] = left;
                    dominoes[k--] = right;
                }
            }
            left = right;
            i = j + 1;
        }
        return dominoes;
    }
};
