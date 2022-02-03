#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int res;
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[-nums1[i]-nums2[j]]++;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mp.count(nums3[i] + nums4[j])) {
                    res += mp[nums3[i] + nums4[j]];
                }
            }
        }
        return res;
    }
};
