#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct cmp {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
        for(int& num : nums) {
            mp[num]++;
        }
        for(auto p : mp) {
            pq.push(p);
            while(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            auto [num, freq] = pq.top();
            pq.pop();
            res.emplace_back(num);
        }
        return res;
    }
};
