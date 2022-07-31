#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int res = 0;

        // nums1[i] aligns with nums2[0]
        for(int i = 0; i < l1; i++) {
            int len = min(l1 - i, l2);
            int k = helper(nums1, nums2, i, 0, len);
            res = max(res, k);
        }
        // nums1[0] aligns with nums2[i]
        for(int i = 0; i < l2; i++) {
            int len = min(l1, l2 - i);
            int k = helper(nums1, nums2, 0, i, len);
            res = max(res, k);
        }

        return res;
    }

    int helper(vector<int>& nums1, vector<int>& nums2, int a, int b, int len) {
        int k = 0, res = 0;
        for(int i = 0; i < len; i++) {
            if(nums1[a] == nums2[b]) {
                k++;
            } else {
                k = 0;
            }
            a++;
            b++;
            res = max(res, k);
        }
        return res;
    }
};
