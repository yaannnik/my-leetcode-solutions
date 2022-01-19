#include <vector>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> win(nums.begin(), nums.begin() + k);
        sort(win.begin(), win.end());
        vector<double> res;
        res.emplace_back(win[k/2] * 0.5 + win[(k-1)/2]*0.5);

        for (int i = k; i < nums.size(); i++)
        {
            win.erase(find(win.begin(), win.end(), nums[i-k]));
            win.insert(lower_bound(win.begin(), win.end(), nums[i]), nums[i]);
            res.emplace_back(win[k/2] * 0.5 + win[(k-1)/2]*0.5);
        }

        return res;
    }
};
