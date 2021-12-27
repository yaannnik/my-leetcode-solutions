/*
 * @lc app=leetcode.cn id=1537 lang=cpp
 *
 * [1537] 最大得分
 */

// @lc code=start
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<long> max_path1 = vector<long>(n1 + 1);
        vector<long> max_path2 = vector<long>(n2 + 1);
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j]) {
                max_path1[i + 1] = nums1[i] + max_path1[i];
                i++;
                continue;
            }
            if(nums1[i] > nums2[j]) {
                max_path2[j + 1] = nums2[j] + max_path2[j];
                j++;
                continue;
            }
            // i == j
            max_path1[i + 1] = max((nums1[i] + max_path1[i]), (nums2[j] + max_path2[j]));
            max_path2[j + 1] = max_path1[i + 1];
            i++;
            j++;
        }
        for(int index = i; index < n1; index++) {
            max_path1[index + 1] = max_path1[index] + nums1[index];
        }
        for(int index = j; index < n2; index++) {
            max_path2[index + 1] = max_path2[index] + nums2[index];
        }
        long res = max(max_path1[n1], max_path2[n2]) % (int)(1e9+7);
        return res;
    }
};
// @lc code=end

