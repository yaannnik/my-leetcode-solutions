#include<vector>
#include<utility>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        for(int i = 0; i < k; i++) {
            pq.push(pair<int,int>(nums[i], i));
        }
        res.emplace_back(pq.top().first);
        for(int i = k; i < nums.size(); i++) {
            pq.push(pair<int,int>(nums[i], i));
            while(pq.top().second <= i - k) {
                pq.pop();
            }
            res.emplace_back(pq.top().first);
        }
        return res;
    }
};
