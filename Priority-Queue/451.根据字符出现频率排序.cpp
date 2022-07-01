#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (pair<char, int>& a, pair<char, int>& b) {
        return a.second == b.second ? a.first > b.first : a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char& ch : s) {
            mp[ch]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        for(auto& p : mp) {
            pq.push(p);
        }
        string res = "";
        while(!pq.empty()) {
            auto [ch, cnt] = pq.top();
            pq.pop();
            for(int i = 0; i < cnt; i++) {
                res += ch;
            }
        }
        return res;
    }
};
