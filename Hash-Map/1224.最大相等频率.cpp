#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mostFreqCnt = 0;
        int mostFreqNum = 0;
        int cnt = 0;
        int res = 0;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(!mp.count(num)) {
                cnt++;
            }
            mp[num]++;

            if(mostFreqNum < mp[num]) {
                mostFreqNum = mp[num];
                mostFreqCnt = 1;
            } else if(mostFreqNum == mp[num]) {
                mostFreqCnt++;
            }
            if((mostFreqNum == 1) || (mostFreqCnt * mostFreqNum == i) || (mostFreqCnt == 1 && mostFreqNum == i / cnt + 1)) {
                // 所有数字都只出现一次 or 有一个数字只出现一次 or (cnt - 1) * (mostFreqNum - 1) + mostFreqNum = i + 1 即一个数字出现的次数比其他多1
                res = i + 1;
            }
        }
        return res;
    }
};
