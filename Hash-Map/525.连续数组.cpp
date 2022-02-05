#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp; // 记录第一次出现0、1差值的位置，采用前缀和
        mp[0] = -1;
        int cnt0 = 0, cnt1 = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                cnt0++;
            } else if(nums[i] == 1) {
                cnt1++;
            }
            if(mp.count(cnt0-cnt1)) {
                res = max(res, i - mp[cnt0-cnt1]);
            } else {
                mp[cnt0-cnt1] = i;
            }
        }
        return res;
    }
};
