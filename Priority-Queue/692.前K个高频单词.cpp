#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (pair<string, int>& a, pair<string, int>& b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string& word : words) {
            mp[word]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for(pair<string, int> p : mp) {
            pq.emplace(p);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> res(k);
        for(int i = k - 1; i >= 0; i--) {
            auto [word, cnt] = pq.top();
            pq.pop();
            res[i] = word;
        }
        return res;
    }
};
