#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        if(nums.empty()) {
            return {};
        }

        unordered_set<int> intersection(nums[0].begin(), nums[0].end());
        for(int i = 1; i < nums.size(); i++) {
            unordered_set<int> tmp;
            for(int& num : nums[i]) {
                if(intersection.count(num)) {
                    tmp.insert(num);
                }
            }
            intersection = tmp;
        }

        vector<int> res;
        for(const int& i : intersection) {
            res.emplace_back(i);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
