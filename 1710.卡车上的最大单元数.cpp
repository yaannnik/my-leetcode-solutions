/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        if(boxTypes.empty()) {
            return 0;
        }
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        for(auto& box : boxTypes) {
            int num = box[0], units = box[1];
            if(truckSize - num >= 0) {
                res += num * units;
                truckSize -= num;
            } else {
                res += truckSize * units;
                return res;
            }
        }
        return res;
    }

    bool static cmp(vector<int>& v1, vector<int>& v2) {
        return (v1[1] > v2[1]);
    }
};
// @lc code=end

