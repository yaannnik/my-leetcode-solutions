#include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        lists.emplace_back(0);
        for(auto& rect : rects) {
            int num = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            lists.emplace_back(lists.back() + num);
        }

    }

    vector<int> pick() {
        int k = rand() % (lists.back() + 1);
        int left = 0, right = this->rects.size() - 1;
        while(left <= right) {
            // 找到第一个比k小的左边界
            int mid = left + (right - left) / 2;
            if(lists[mid] > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        vector<int> target = rects[right];
        int x = target[2] - target[0] + 1;
        int y = target[3] - target[1] + 1;
        return {rand() % x + target[0], rand() % y + target[1]};
    }

    vector<int> lists;
    vector<vector<int>> rects;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
