#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct cmp {
    bool operator() (pair<char, int>& a, pair<char, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(char& ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        for(auto& p : mp) {
            pq.emplace(p);
        }

        string res = "";
        while(!pq.empty()) {
            auto [ch, cnt] = pq.top();
            pq.pop();
            // cout << ch << endl;
            if(res.empty() || ch != res.back()) {
                res += ch;
                cnt--;
                if(cnt != 0) {
                    pq.emplace(ch, cnt);
                }
            } else if(ch == res.back()) {
                if(pq.empty()) {
                    return "";
                }
                auto [ch1, cnt1] = pq.top();
                pq.pop();
                // cout << ch1 << endl;
                res += ch1;
                cnt1--;
                pq.emplace(ch, cnt);
                if(cnt1 != 0) {
                    pq.emplace(ch1, cnt1);
                }
            }
            // cout << "res: " << res << endl;
        }
        return res;
    }
};
