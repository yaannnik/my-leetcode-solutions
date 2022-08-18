#include <vector>
#include <unordered_map>
using namespace std;

class SparseVector {
public:

    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                mp[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        for(auto& [index, num] : mp) {
            if(vec.mp.count(index)) {
                product += mp[index] * vec.mp[index];
            }
        }
        return product;
    }

    unordered_map<int, int> mp;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
