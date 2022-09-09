#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int p1 = (m + n + 1)/2, p2 = (m + n + 2)/2;
        return (findKthElement(nums1, nums2, p1) + findKthElement(nums1, nums2, p2)) * 1.0 / 2;
    }

    int findKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int idx1 = 0, idx2 = 0;

        while(1) {
            if(idx1 == m) {
                return nums2[idx2 + k - 1];
            }
            if(idx2 == n) {
                return nums1[idx1 + k - 1];
            }

            if(k == 1) {
                return min(nums1[idx1], nums2[idx2]);
            }

            int idx1_end = min(idx1 + (k / 2) - 1, m - 1);
            int idx2_end = min(idx2 + (k / 2) - 1, n - 1);

            if(nums1[idx1_end] <= nums2[idx2_end]) {
                k -= (idx1_end - idx1 + 1);
                idx1 = idx1_end + 1;
            } else {
                k -= (idx2_end - idx2 + 1);
                idx2 = idx2_end + 1;
            }
        }
    }

    int findKthElement_bak(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0, j = 0;
        int res = 0;

        for(int cnt = 0; cnt < k; cnt++) {
            if(i == nums1.size()) {
                res = nums2[j++];
                continue;
            }
            if(j == nums2.size()) {
                res = nums1[i++];
                continue;
            }
            if(nums1[i] <= nums2[j]) {
                res = nums1[i++];
            } else {
                res = nums2[j++];
            }
        }

        return res;
    }
};
